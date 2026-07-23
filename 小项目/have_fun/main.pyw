import math
import random
import time
import tkinter as tk
from tkinter import font as tkfont

# ============================================================
# 1) 名字修改区（最常改）
# 只需要改这里：NAME = "你的名字"
# ============================================================
NAME = "舒飞虎"

# ============================================================
# 2) 播放逻辑参数（按你给的示例逻辑）
# ============================================================
MAX_WINDOWS = 300
POP_INTERVAL_MS = 120

# [MOD] 10秒后停止创建新弹窗，进入“渐隐收尾”流程
SPAWN_DURATION_SEC = 10

# ============================================================
# 3) 弹窗尺寸参数
# ============================================================
# [MOD] 普通弹窗改为接近终章比例（终章约 560:220 = 2.55）
NORMAL_WIDTH_RANGE = (320, 430)
NORMAL_HEIGHT_RANGE = (126, 170)
FINAL_WIDTH = 560
FINAL_HEIGHT = 220

# ============================================================
# 4) 纯色视觉参数（不使用渐变）
# ============================================================
CORNER_RADIUS = 18
FINAL_CORNER_RADIUS = 24

# [MOD] 主题切换：只改这一项即可切换整套配色（soft / vivid）
THEME_MODE = "soft"

THEME_PRESETS = {
    "soft": {
        "cards": [
            {"bg": "#FFE7EE", "border": "#F6BBCB", "accent": "#EA7FA0", "text": "#3A3243"},
            {"bg": "#E8F4FF", "border": "#BFDDF7", "accent": "#5B9BD5", "text": "#263949"},
            {"bg": "#ECF8EE", "border": "#C9E7CF", "accent": "#62B27F", "text": "#2D3C33"},
            {"bg": "#FFF7E1", "border": "#F2DFAC", "accent": "#D1A64B", "text": "#4A3D25"},
            {"bg": "#F3ECFF", "border": "#D9C8F6", "accent": "#9D78D3", "text": "#3E3353"},
        ],
        "final": {
            "bg": "#1F2A44",
            "border": "#F1CC7A",
            "accent": "#F59E0B",
            "text": "#F8FAFC",
        },
    },
    "vivid": {
        "cards": [
            {"bg": "#FFDCE6", "border": "#F39BB4", "accent": "#E64980", "text": "#3A1C30"},
            {"bg": "#DFF1FF", "border": "#88C9F9", "accent": "#1D89E4", "text": "#14344A"},
            {"bg": "#DEF9E7", "border": "#86D7A8", "accent": "#2FA96B", "text": "#1C3A2B"},
            {"bg": "#FFF2CC", "border": "#F2C86B", "accent": "#D68910", "text": "#4B340F"},
            {"bg": "#EEE1FF", "border": "#BE9BF0", "accent": "#7C4DCC", "text": "#2F2148"},
        ],
        "final": {
            "bg": "#111827",
            "border": "#F7C65A",
            "accent": "#F59E0B",
            "text": "#F9FAFB",
        },
    },
}

_selected_theme = THEME_PRESETS.get(THEME_MODE, THEME_PRESETS["soft"])
CARD_THEMES = _selected_theme["cards"]
FINAL_THEME = _selected_theme["final"]

# ============================================================
# 5) 动画参数
# ============================================================
# [MOD] 动画目标刷新间隔提高，配合时间驱动插值，观感更顺滑
ANIM_FRAME_MS = 10
FADE_IN_MS = 280
WINDDOWN_FADE_MIN_MS = 900
WINDDOWN_FADE_MAX_MS = 1600
WINDDOWN_STAGGER_MAX_MS = 900
FINAL_STAY_MS = 2400
FINAL_FADE_MS = 950
# [MOD] 普通弹窗停止后，延时几秒再出现终章与确认按钮
FINAL_APPEAR_DELAY_MS = 2200
# [MOD] 普通弹窗全部消失后，再缓一下才消失终章
FINAL_AFTER_NORMALS_DELAY_MS = 700

# [MOD] 终章确认按钮参数（屏幕底部）
CONFIRM_BUTTON_TEXT = "好"
CONFIRM_BUTTON_WIDTH = 176
CONFIRM_BUTTON_HEIGHT = 66
CONFIRM_BUTTON_BOTTOM_MARGIN = 26
CONFIRM_BUTTON_FADE_MS = 420
# [MOD] 缓动柔和度：越接近1越偏正弦（更柔和），越接近0越偏smoothstep（更利落）
EASE_SINE_BLEND = 0.82

# ============================================================
# 6) 字体参数（更柔和）
# ============================================================
FONT_SIZE_NORMAL = 15
FONT_SIZE_FINAL = 24
LINE_HEIGHT_MULTIPLIER = 1.45

FONT_FAMILIES_WINDOWS = ["Microsoft YaHei UI", "Microsoft YaHei", "Segoe UI", "PingFang SC"]
FONT_FAMILIES_MAC = ["SF Pro Text", "PingFang SC", "Helvetica Neue"]
FONT_FAMILIES_LINUX = ["Roboto", "Noto Sans CJK SC", "Noto Sans", "DejaVu Sans"]

# ============================================================
# 7) 祝福语分类区（保留可绑名 / 不绑名）
# ============================================================
BINDABLE_BLESSINGS = {
    "情感/情绪疏导": [
        "{name}，考研的压力很真，但你更真实地在变强",
        "{name}，不必把每一天都看成决战，慢下来也是为了更稳地冲刺",
        "{name}，紧张时深呼吸，告诉自己你已经准备得很好了",
        "{name}，焦虑只是一时，你对北大的梦想却可以长久坚持",
        "{name}，别因为一时的不安，忽略了你一路走来的努力",
        "{name}，允许自己有情绪，别让考试的声音盖过你内心的信心",
        "{name}，你不是孤军奋斗，我们都相信你能拿下北大",
    ],
    "成长/行动": [
        "{name}，北大是你的目标，你已经在用坚持一步步靠近它了",
        "{name}，每一次早读和冲刺，都是你走进北大的桥梁",
        "{name}，遇到难题别慌，稳住心态再去把它拆开",
        "{name}，现在的每份努力，都会在未来为你撑起更大的舞台",
        "{name}，你的目标很大，正是因为你有这样的勇气和实力",
        "{name}，这段备考路不容易，但你的执着会把它变成光彩",
        "{name}，不必每天都轰轰烈烈，持续前进就是最强的力量",
        "{name}，你的进步不是一瞬，而是一点一滴积累起来的底气",
    ],
    "友情/社交": [
        "{name}，备考路上有人陪你一起努力，比成绩更值得记住",
        "{name}，朋友的鼓励会让你在冲刺北大时更有底气",
        "{name}，适当说出你的压力，好的朋友会给你更多信心",
        "{name}，你值得被理解和支持，别把所有负担都揽在自己身上",
        "{name}，真正的友情，是在你最疲惫的时候还愿意和你并肩走下去",
        "{name}，向你身边的支持者致敬，他们是你冲刺北大的秘密武器",
        "{name}，把时间留给让你更强的人和事，别被无谓的消耗拖住",
    ],
    "生活/趣味": [
        "{name}，考研也要照顾好自己，身体和心情都是最重要的底盘",
        "{name}，适当放松不是偷懒，而是为下一轮更好地冲刺蓄力",
        "{name}，把复习和休息都安排得恰到好处，你会更有力量向北大迈进",
        "{name}，愿你在备考的日子里，也能发现那些小小的温暖和乐趣",
        "{name}，忙碌之余，别忘了给自己一个轻松的笑容",
        "{name}，你的每一次努力，都会在未来以一种温柔的方式回馈你",
        "{name}，保持好奇和热爱，让学习变成你前进的动力",
    ],
    "新年祝福": [
        "{name}，新年愿你稳扎稳打，北大录取通知书终将到手",
        "{name}，新的一年，愿你把考研压力化成冲刺动力",
        "{name}，愿你在2026年的每一个早晨，都比昨天更靠近北大",
        "{name}，新年不忘梦想，北大既是目标，也是你坚持的理由",
        "{name}，愿你所有的笔记和习题，最后都变成通往北大的通行证",
        "{name}，新春将至，愿你保持初心，从容迎接考研最后一战",
        "{name}，愿你奔赴北大的路上，带着自信与从容前行",
    ],
}

GENERIC_BLESSINGS = {
    "情感/情绪疏导": [
        "备考再紧张，也请记得给自己一个善意的暂停",
        "你对北大的渴望可以很强，但别忘了温柔对待自己",
        "再难的日子也会过去，你的努力早晚会被看到",
        "情绪会来又会去，你的目标却会因为你而越来越清晰",
        "允许自己不完美，完美不是考研成功的唯一标准",
        "你现在的紧张，是因为你对未来有期待，这很正常",
        "别让压力绑架你，给自己一点空间，继续向前走",
    ],
    "成长/行动": [
        "每一次坚持，都会把你和北大之间的距离拉近一点",
        "你不是在为一个成绩而努力，是在为一个更强的自己积累底气",
        "把大目标分成小目标，一步步走会更稳更有力量",
        "哪怕只是做了一点点题，那也是进步，不要轻易否定自己",
        "成长不是瞬间爆发，而是日复一日的积累和相信",
        "你正在把自己的野心和行动变成现实，这本身就很了不起",
        "稳扎稳打地前进，就是你现在最好的状态",
        "只要你不放弃，北大就是你勇气和努力的归宿之一",
    ],
    "友情/社交": [
        "考研路上，有人愿意陪你一起读题、一起加油，就很幸福",
        "把时间留给愿意理解你的朋友，他们会是你最好的后援",
        "你不必独自承担所有压力，适当分享会让你更轻松",
        "真正的友情，会在你最疲惫的时候，给你多一句‘你可以的’",
        "别怕打扰别人寻求帮助，真心的支持会让你更有力量",
        "在备考期间，学会说‘我需要休息’，那也是成熟的表现",
        "与你同频的人，会在你追北大时替你鼓掌",
    ],
    "生活/趣味": [
        "备考期间也要有小小的快乐，生活才会更有能量",
        "好的复习节奏，是把学习和休息都安排得恰到好处",
        "偶尔放松一下，才能更清醒地继续冲刺北大",
        "你的生活不只是考试，还有你认真对待自己的方式",
        "愿你在备考路上，也能发现一句好听的话，一杯好喝的茶",
        "把简单的日子过得舒服，备考才能走得更远",
        "你越懂得照顾自己，越能在考场上发挥出真实水平",
    ],
    "新年祝福": [
        "新年愿你以最平和的状态迎战考研，北大终会欢迎你",
        "新的一年，愿你把每一次练习都当作通往北大的阶梯",
        "愿你在2026年，把梦想写进行动，每一页都值得回忆",
        "新春临近，愿你继续坚定前行，不负这一年努力",
        "愿你把冲刺期看成给未来自己的最好礼物",
        "新年不只是新的开始，也是你离北大更近的一年",
        "愿你带着从容与自信，走进考场，走向你想要的未来",
    ],
}

FINAL_BLESSING_TEMPLATE = "{name}，冲刺北大加油，梦想会在你坚持中到来"

def flatten_blessings(grouped_messages):
    flat = []
    for _, messages in grouped_messages.items():
        for message in messages:
            flat.append(message)
    return flat

def pick_font_family(root):
    system_name = root.tk.call("tk", "windowingsystem")
    if system_name == "aqua":
        candidates = FONT_FAMILIES_MAC
    elif system_name == "x11":
        candidates = FONT_FAMILIES_LINUX
    else:
        candidates = FONT_FAMILIES_WINDOWS

    available = set(tkfont.families(root))
    for family in candidates:
        if family in available:
            return family
    return "TkDefaultFont"

def random_blessing(bindable_pool, generic_pool):
    use_bindable = random.random() < 0.55
    if use_bindable:
        return random.choice(bindable_pool).format(name=NAME)
    return random.choice(generic_pool)

def draw_rounded_rect(canvas, x1, y1, x2, y2, radius, **kwargs):
    radius = max(1, int(radius))
    points = [
        x1 + radius,
        y1,
        x2 - radius,
        y1,
        x2,
        y1,
        x2,
        y1 + radius,
        x2,
        y2 - radius,
        x2,
        y2,
        x2 - radius,
        y2,
        x1 + radius,
        y2,
        x1,
        y2,
        x1,
        y2 - radius,
        x1,
        y1 + radius,
        x1,
        y1,
    ]
    return canvas.create_polygon(points, smooth=True, splinesteps=24, **kwargs)

def ease_in_out(progress):
    p = min(1.0, max(0.0, progress))
    # [MOD] 用正弦 + smoothstep 混合曲线，起停更软，避免“顿挫感”
    sine = 0.5 - 0.5 * math.cos(math.pi * p)
    smooth = p * p * (3 - 2 * p)
    return sine * EASE_SINE_BLEND + smooth * (1.0 - EASE_SINE_BLEND)

def hex_to_rgb(hex_color):
    value = hex_color.lstrip("#")
    return int(value[0:2], 16), int(value[2:4], 16), int(value[4:6], 16)

def rgb_to_hex(rgb):
    r = max(0, min(255, int(rgb[0])))
    g = max(0, min(255, int(rgb[1])))
    b = max(0, min(255, int(rgb[2])))
    return f"#{r:02X}{g:02X}{b:02X}"

def mix_hex(color_a, color_b, ratio):
    r = min(1.0, max(0.0, ratio))
    ar, ag, ab = hex_to_rgb(color_a)
    br, bg, bb = hex_to_rgb(color_b)
    return rgb_to_hex(
        (
            ar + (br - ar) * r,
            ag + (bg - ag) * r,
            ab + (bb - ab) * r,
        )
    )

class BlessingPopup:
    def __init__(self, app, text, is_final=False, on_closed=None):
        self.app = app
        self.text = text
        self.is_final = is_final
        self.on_closed = on_closed
        self.is_closing = False
        self.destroyed = False

        self.theme = dict(FINAL_THEME if is_final else random.choice(CARD_THEMES))

        if is_final:
            self.width = FINAL_WIDTH
            self.height = FINAL_HEIGHT
            self.x, self.base_y = self._pick_center_position()
        else:
            self.width = random.randint(*NORMAL_WIDTH_RANGE)
            self.height = random.randint(*NORMAL_HEIGHT_RANGE)
            self.x, self.base_y = self._pick_random_position()

        self.current_alpha = 0.0
        self.current_y = self.base_y + 10

        self.window = tk.Toplevel(self.app.root)
        self.window.overrideredirect(True)
        self.window.attributes("-topmost", True)

        self.bg_key = self.app.transparent_key
        self.window.configure(bg=self.bg_key)

        if self.app.support_transparent_key:
            try:
                self.window.wm_attributes("-transparentcolor", self.bg_key)
            except tk.TclError:
                pass

        self.canvas = tk.Canvas(
            self.window,
            width=self.width,
            height=self.height,
            bg=self.bg_key,
            bd=0,
            highlightthickness=0,
        )
        self.canvas.pack(fill="both", expand=True)

        self._draw_static_card()
        self._apply_state(self.current_alpha, self.current_y)
        self.fade_in()

    def _pick_random_position(self):
        screen_w = self.app.root.winfo_screenwidth()
        screen_h = self.app.root.winfo_screenheight()
        margin = 16
        x = random.randint(margin, max(margin, screen_w - self.width - margin))
        y = random.randint(margin + 36, max(margin + 36, screen_h - self.height - margin))
        return x, y

    def _pick_center_position(self):
        screen_w = self.app.root.winfo_screenwidth()
        screen_h = self.app.root.winfo_screenheight()
        x = (screen_w - self.width) // 2
        y = (screen_h - self.height) // 2 - 12
        return x, y

    def _draw_static_card(self):
        self.canvas.delete("all")

        card_x1 = 0
        card_y1 = 0
        card_x2 = self.width - 1
        card_y2 = self.height - 1

        draw_rounded_rect(
            self.canvas,
            card_x1,
            card_y1,
            card_x2,
            card_y2,
            FINAL_CORNER_RADIUS if self.is_final else CORNER_RADIUS,
            fill=self.theme["bg"],
            outline=self.theme["border"],
            width=2,
        )

        if self.is_final:
            draw_rounded_rect(
                self.canvas,
                card_x1 + 24,
                card_y1 + 20,
                card_x2 - 24,
                card_y1 + 34,
                8,
                fill=self.theme["accent"],
                outline="",
            )

            self.canvas.create_text(
                self.width // 2,
                54,
                text="Happy New Year !",
                fill="#FCD67D",
                font=(self.app.font_family, 12, "bold"),
            )

            self.canvas.create_text(
                self.width // 2,
                self.height // 2 + 28,
                text=self.text,
                fill=self.theme["text"],
                font=(self.app.font_family, FONT_SIZE_FINAL, "bold"),
                width=self.width - 72,
                justify="center",
            )
        else:
            # [MOD] 普通弹窗效仿终章审美：内层边框线 + 顶部徽章条 + 层次化文字。
            inner_border_color = mix_hex(self.theme["border"], "#FFFFFF", 0.35)

            draw_rounded_rect(
                self.canvas,
                card_x1 + 8,
                card_y1 + 8,
                card_x2 - 8,
                card_y2 - 8,
                max(8, CORNER_RADIUS - 6),
                fill="",
                outline=inner_border_color,
                width=1,
            )

            draw_rounded_rect(
                self.canvas,
                card_x1 + 22,
                card_y1 + 16,
                card_x2 - 22,
                card_y1 + 30,
                8,
                fill=self.theme["accent"],
                outline="",
            )

            self.canvas.create_text(
                self.width // 2,
                self.height // 2 + 9,
                text=self.text,
                fill=self.theme["text"],
                font=(self.app.font_family, FONT_SIZE_NORMAL, "normal"),
                width=self.width - 40,
                justify="center",
            )

    def _apply_state(self, alpha, y):
        self.current_alpha = max(0.0, min(1.0, alpha))
        self.current_y = y

        self.window.geometry(f"{self.width}x{self.height}+{self.x}+{int(self.current_y)}")

        try:
            self.window.wm_attributes("-alpha", self.current_alpha)
        except tk.TclError:
            pass

    def _animate(self, start_alpha, end_alpha, start_y, end_y, duration_ms, on_done=None):
        duration_ms = max(1, int(duration_ms))
        start_ts = time.perf_counter()

        def tick():
            if self.destroyed:
                return

            elapsed_ms = (time.perf_counter() - start_ts) * 1000.0
            progress = min(1.0, elapsed_ms / duration_ms)
            eased = ease_in_out(progress)

            alpha = start_alpha + (end_alpha - start_alpha) * eased
            y = start_y + (end_y - start_y) * eased
            self._apply_state(alpha, y)

            if progress < 1.0:
                self.window.after(ANIM_FRAME_MS, tick)
            else:
                if on_done:
                    on_done()

        tick()

    def fade_in(self):
        self._animate(0.0, 0.97, self.base_y + 10, self.base_y, FADE_IN_MS)

    def start_fade_out(self, duration_ms, delay_ms=0):
        if self.is_closing or self.destroyed:
            return

        self.is_closing = True

        def begin():
            if self.destroyed:
                return
            self._animate(
                self.current_alpha,
                0.0,
                self.current_y,
                self.base_y - 14,
                duration_ms,
                on_done=self.destroy,
            )

        if delay_ms > 0:
            self.window.after(delay_ms, begin)
        else:
            begin()

    def destroy(self):
        if self.destroyed:
            return

        self.destroyed = True
        try:
            self.window.destroy()
        except tk.TclError:
            pass

        if self.on_closed:
            self.on_closed(self)

class FinalConfirmButton:
    """终章确认按钮：点击后触发统一收尾。"""

    def __init__(self, app, on_confirm):
        self.app = app
        self.on_confirm = on_confirm
        self.destroyed = False
        self.disabled = False

        self.width = CONFIRM_BUTTON_WIDTH
        self.height = CONFIRM_BUTTON_HEIGHT

        screen_w = self.app.root.winfo_screenwidth()
        screen_h = self.app.root.winfo_screenheight()
        self.x = (screen_w - self.width) // 2
        self.base_y = screen_h - self.height - CONFIRM_BUTTON_BOTTOM_MARGIN

        self.current_alpha = 0.0
        self.current_y = self.base_y + 8

        self.window = tk.Toplevel(self.app.root)
        self.window.overrideredirect(True)
        self.window.attributes("-topmost", True)
        self.bg_key = self.app.transparent_key
        self.window.configure(bg=self.bg_key)

        if self.app.support_transparent_key:
            try:
                self.window.wm_attributes("-transparentcolor", self.app.transparent_key)
            except tk.TclError:
                pass

        self.canvas = tk.Canvas(
            self.window,
            width=self.width,
            height=self.height,
            bg=self.bg_key,
            bd=0,
            highlightthickness=0,
            cursor="hand2",
        )
        self.canvas.pack(fill="both", expand=True)

        self._draw_button(disabled=False)
        self._apply_state(self.current_alpha, self.current_y)

        self.canvas.bind("<Button-1>", self._handle_click)
        self.window.bind("<Button-1>", self._handle_click)
        self.fade_in()

    def _draw_button(self, disabled):
        self.canvas.delete("all")

        if disabled:
            bg_color = mix_hex(FINAL_THEME["bg"], "#A0AEC0", 0.55)
            border_color = mix_hex(FINAL_THEME["border"], "#A0AEC0", 0.55)
            text_color = "#E2E8F0"
        else:
            bg_color = FINAL_THEME["bg"]
            border_color = FINAL_THEME["border"]
            text_color = FINAL_THEME["text"]

        draw_rounded_rect(
            self.canvas,
            0,
            0,
            self.width - 1,
            self.height - 1,
            18,
            fill=bg_color,
            outline=border_color,
            width=2,
        )

        draw_rounded_rect(
            self.canvas,
            10,
            10,
            self.width - 11,
            self.height - 11,
            14,
            fill="",
            outline=mix_hex(border_color, "#FFFFFF", 0.30),
            width=1,
        )

        self.canvas.create_text(
            self.width // 2,
            33,
            text=CONFIRM_BUTTON_TEXT,
            fill=text_color,
            font=(self.app.font_family, 18, "bold"),
        )

    def _apply_state(self, alpha, y):
        self.current_alpha = max(0.0, min(1.0, alpha))
        self.current_y = y
        self.window.geometry(f"{self.width}x{self.height}+{self.x}+{int(self.current_y)}")
        try:
            self.window.wm_attributes("-alpha", self.current_alpha)
        except tk.TclError:
            pass

    def _animate(self, start_alpha, end_alpha, start_y, end_y, duration_ms, on_done=None):
        duration_ms = max(1, int(duration_ms))
        start_ts = time.perf_counter()

        def tick():
            if self.destroyed:
                return

            elapsed_ms = (time.perf_counter() - start_ts) * 1000.0
            progress = min(1.0, elapsed_ms / duration_ms)
            eased = ease_in_out(progress)

            alpha = start_alpha + (end_alpha - start_alpha) * eased
            y = start_y + (end_y - start_y) * eased
            self._apply_state(alpha, y)

            if progress < 1.0:
                self.window.after(ANIM_FRAME_MS, tick)
            else:
                if on_done:
                    on_done()

        tick()

    def fade_in(self):
        self._animate(0.0, 0.98, self.base_y + 8, self.base_y, 250)

    def set_disabled(self):
        if self.destroyed or self.disabled:
            return
        self.disabled = True
        self._draw_button(disabled=True)
        self.canvas.configure(cursor="arrow")

    def start_fade_out(self, duration_ms=CONFIRM_BUTTON_FADE_MS, on_done=None):
        if self.destroyed:
            return

        self._animate(
            self.current_alpha,
            0.0,
            self.current_y,
            self.base_y + 8,
            duration_ms,
            on_done=lambda: self._destroy_and_callback(on_done),
        )

    def _destroy_and_callback(self, on_done):
        self.destroy()
        if on_done:
            on_done()

    def _handle_click(self, _event):
        if self.destroyed or self.disabled:
            return
        self.on_confirm()

    def destroy(self):
        if self.destroyed:
            return

        self.destroyed = True
        try:
            self.window.destroy()
        except tk.TclError:
            pass

class BlessingBarrageApp:
    def __init__(self):
        self.root = tk.Tk()
        self.root.withdraw()

        self.bindable_pool = flatten_blessings(BINDABLE_BLESSINGS)
        self.generic_pool = flatten_blessings(GENERIC_BLESSINGS)

        self.font_family = pick_font_family(self.root)

        self.window_count = 0
        self.spawning_enabled = True
        self.winddown_started = False
        self.release_started = False
        self.final_popup_shown = False
        self.final_fade_scheduled = False

        self.active_popups = set()
        self.final_popup = None
        self.confirm_button = None

        self.transparent_key = "#010203"
        # [MOD] 统一使用 transparentcolor 做圆角镂空，避免暗角
        self.support_transparent_key = True

    def create_warm_tip(self):
        if not self.spawning_enabled:
            return

        tip = random_blessing(self.bindable_pool, self.generic_pool)
        popup = BlessingPopup(self, text=tip, is_final=False, on_closed=self.on_popup_closed)
        self.active_popups.add(popup)
        self.window_count += 1

    def auto_pop_tips(self, interval=POP_INTERVAL_MS):
        # 逻辑对齐你给的示例：固定间隔创建，数量到上限则停止
        if self.spawning_enabled and self.window_count < MAX_WINDOWS:
            self.create_warm_tip()
            self.root.after(interval, self.auto_pop_tips, interval)
        elif self.spawning_enabled:
            self.spawning_enabled = False
            print(f"已达到最大弹窗数量（{MAX_WINDOWS}个），自动暂停")

    def start_winddown(self):
        # [MOD] 启动后10秒进入收尾准备：停止新弹窗，停顿几秒后再展示终章与确认按钮。
        if self.winddown_started:
            return

        self.winddown_started = True
        self.spawning_enabled = False

        self.root.after(FINAL_APPEAR_DELAY_MS, self.show_final_stage)

    def on_popup_closed(self, popup):
        self.active_popups.discard(popup)
        self.maybe_schedule_final_fade()
        self.try_finish()

    def show_final_stage(self):
        if not self.winddown_started:
            return
        self.show_final_popup()
        self.show_confirm_button()

    def show_final_popup(self):
        if self.final_popup_shown:
            return

        self.final_popup_shown = True
        final_text = FINAL_BLESSING_TEMPLATE.format(name=NAME)

        self.final_popup = BlessingPopup(
            self,
            text=final_text,
            is_final=True,
            on_closed=self.on_final_closed,
        )

    def on_final_closed(self, _popup):
        self.final_popup = None
        self.try_finish()

    def show_confirm_button(self):
        if self.confirm_button is not None:
            return
        self.confirm_button = FinalConfirmButton(self, on_confirm=self.confirm_release)

    def confirm_release(self):
        if self.release_started:
            return

        self.release_started = True

        if self.confirm_button:
            self.confirm_button.set_disabled()
            self.confirm_button.start_fade_out(
                duration_ms=CONFIRM_BUTTON_FADE_MS,
                on_done=self.on_confirm_button_closed,
            )

        for popup in list(self.active_popups):
            popup.start_fade_out(
                duration_ms=random.randint(WINDDOWN_FADE_MIN_MS, WINDDOWN_FADE_MAX_MS),
                delay_ms=random.randint(0, WINDDOWN_STAGGER_MAX_MS),
            )

        # [MOD] 普通弹窗先全部消失，之后再缓一下才轮到终章。
        self.maybe_schedule_final_fade()

    def on_confirm_button_closed(self):
        self.confirm_button = None
        self.maybe_schedule_final_fade()
        self.try_finish()

    def maybe_schedule_final_fade(self):
        if not self.release_started:
            return
        if self.final_fade_scheduled:
            return
        if self.active_popups:
            return
        if self.final_popup is None:
            self.try_finish()
            return

        self.final_fade_scheduled = True
        self.root.after(FINAL_AFTER_NORMALS_DELAY_MS, self.fade_final_popup)

    def fade_final_popup(self):
        if self.final_popup is None:
            self.try_finish()
            return
        if self.final_popup.destroyed:
            self.try_finish()
            return
        self.final_popup.start_fade_out(FINAL_FADE_MS)

    def try_finish(self):
        if not self.release_started:
            return

        if self.active_popups:
            return

        if self.final_popup is not None:
            return

        if self.confirm_button is not None:
            return

        self.root.after(120, self.root.destroy)

    def run(self):
        self.auto_pop_tips(POP_INTERVAL_MS)
        self.root.after(int(SPAWN_DURATION_SEC * 1000), self.start_winddown)
        self.root.mainloop()

if __name__ == "__main__":
    app = BlessingBarrageApp()
    app.run()
