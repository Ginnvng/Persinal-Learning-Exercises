import math
import random
import time
import tkinter as tk
from tkinter import font as tkfont

# ============================================================
# 1) 名字修改区（最常改）
# 只需要改这里：NAME = "你的名字"
# ============================================================
NAME = "张泉奕"

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

# [MOD] 主题切换：张泉奕专属（spring_stream / clear_morning）
THEME_MODE = "spring_stream"

THEME_PRESETS = {
    "spring_stream": {
        "cards": [
            {"bg": "#F3FAFF", "border": "#C7E0F2", "accent": "#74B6E6", "title": "#3A6B93", "text": "#26465E"},
            {"bg": "#F4FCF8", "border": "#C9E9D9", "accent": "#78C6A2", "title": "#3A7A60", "text": "#274F40"},
            {"bg": "#F8F6FF", "border": "#DAD1F3", "accent": "#A99BDF", "title": "#655A98", "text": "#413A64"},
            {"bg": "#FFF8F3", "border": "#EFDCCB", "accent": "#D5B48E", "title": "#8A6A4B", "text": "#503D2D"},
            {"bg": "#F6FAFF", "border": "#CFDCF2", "accent": "#8BB2E5", "title": "#4A6999", "text": "#2E4668"},
        ],
        "final": {
            "bg": "#F1F9FF",
            "border": "#BFD9EE",
            "accent": "#78BDE8",
            "title": "#3E6D93",
            "text": "#27475F",
        },
    },
    "clear_morning": {
        "cards": [
            {"bg": "#ECF8FF", "border": "#C2DEF2", "accent": "#6EB1DF", "title": "#35668D", "text": "#23455F"},
            {"bg": "#EEFBF5", "border": "#C4E8DA", "accent": "#6DBD9B", "title": "#33735B", "text": "#244A3D"},
            {"bg": "#FFF6FA", "border": "#EBCFDF", "accent": "#D5A0BF", "title": "#8B5571", "text": "#4C2F3F"},
            {"bg": "#F3F6FF", "border": "#CDD8F2", "accent": "#93AEE5", "title": "#4E6698", "text": "#334868"},
            {"bg": "#F9F7FF", "border": "#DDD5F3", "accent": "#B4A7E4", "title": "#6D609D", "text": "#453D66"},
        ],
        "final": {
            "bg": "#EEF7FF",
            "border": "#BDD9EF",
            "accent": "#77B8E6",
            "title": "#3D6D95",
            "text": "#26485F",
        },
    },
}

_selected_theme = THEME_PRESETS.get(THEME_MODE, THEME_PRESETS["spring_stream"])
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
NORMAL_BADGE_TEXT = "清泉柔语"
FINAL_HEADER_TEXT = "Happy New Year !"
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
        "{name}，像清泉一样保持澄澈，像晨光一样一路发亮",
        "{name}，你的温柔和坚定可以同时存在，这就是你的光",
        "{name}，你不用一直逞强，偶尔慢一点也很酷",
        "{name}，不用逼自己立刻好起来，给自己一点时间，你已经很棒了",
        "{name}，难过时就抱抱自己，天亮之后我们再出发",
        "{name}，允许自己有情绪，但别让情绪定义你的人生",
        "{name}，焦虑的时候先做手头的事，行动会把心拉回正轨",
        "{name}，不要因为一时迷茫，就否定自己走过的所有路",
        "{name}，放下过去的遗憾吧，你值得更好的开始",
    ],
    "成长/行动": [
        "{name}，名字里的“奕”是光彩，慢慢走你也会很耀眼",
        "{name}，哪怕走得慢，也别后退，你走的每一步都算数",
        "{name}，别盯着眼前的坎，你翻山越岭的能力从来没消失过",
        "{name}，你的内心比你想象中更强大，这点风雨打不倒你",
        "{name}，此刻的难，只是为了铺垫未来的高光，你熬得过去",
        "{name}，每一份坚持，都在悄悄为你铺路",
        "{name}，你的潜力很大，别轻易给自己设限",
        "{name}，不慌不忙地前进，也是一种很厉害的节奏",
        "{name}，向阳而生，逐光而行，你会看见更好的风景",
    ],
    "友情/社交": [
        "{name}，不必刻意合群，你的光芒自会吸引同频的人",
        "{name}，远离消耗你的关系，这不是冷漠，是对自己的负责",
        "{name}，真诚永远是必杀技，做自己，自然会有人珍惜你",
        "{name}，圈子虽小，干净就好；朋友不多，真心就够",
        "{name}，你值得被坚定地选择，而不是在关系里患得患失",
        "{name}，学会说“不”，你会发现，生活轻松了很多",
        "{name}，愿你在人群中不迷失，在独处时不孤单",
        "{name}，好的友情是彼此成就，而不是互相牵绊",
    ],
    "生活/趣味": [
        "{name}，把热爱装进生活，平凡的日子也能开出花来",
        "{name}，不必追求完美，热烈地活着，本身就很了不起",
        "{name}，勇敢去做想做的事，别让“以后”变成遗憾",
        "{name}，生活不是赛道，是旷野，你可以按自己的节奏奔跑",
        "{name}，累了就停下来歇歇，充电是为了更好地出发",
        "{name}，你的生活，不需要别人来定义，自己喜欢就好",
        "{name}，抓住每一个小确幸，这就是生活的意义",
        "{name}，不慌不忙，不卑不亢，把日子过成自己喜欢的模样",
    ],
    "新年祝福": [
        "{name}，愿你新岁如泉水长流，心里有光，步步生辉",
        "{name}，新岁启封，愿你乘风破浪，光芒万丈",
        "{name}，新年不设限，你的未来，有无限可能",
        "{name}，愿你新的一年，知不足而奋进，望远山而前行",
        "{name}，新春快乐，愿你所有的努力，都能落地生花",
        "{name}，新的一年，愿你初心不改，勇往直前",
        "{name}，岁序更新，愿你跨过山海，终见繁花",
        "{name}，新岁将至，愿你放下过往，轻装上阵，奔赴美好",
        "{name}，2026，愿你一路生花，所求皆如愿，所行皆坦途",
    ],
}

GENERIC_BLESSINGS = {
    "情感/情绪疏导": [
        "愿你心有清泉般的平静，也有迎风向前的勇气",
        "哪怕眼前一片黑暗，也要相信，光正在赶来的路上",
        "情绪不是敌人，学会与它共处，你会变得更强大",
        "不用急着赶路，停下来整理心情，也是一种前进",
        "你不需要完美，你只需要做真实的、努力的自己",
        "迷茫时就扎根，沉淀自己，时机到了自然会发芽",
        "别让过去的错误，惩罚现在的自己",
        "不要因为别人的评价，就怀疑自己的价值",
        "心怀希望，就永远不会被打败",
    ],
    "成长/行动": [
        "所有的低谷，都是为了让你站得更高",
        "你的坚强不是天生的，是你一步步熬出来的",
        "把大目标拆成小步骤，你会发现，原来自己这么厉害",
        "每一份小努力，都值得被认真肯定",
        "生活没有标准答案，你走的路，就是最好的答案",
        "不慌不忙，从容淡定，这是生活的大智慧",
        "抓住每一个机会，去成为更好的自己",
        "向阳而生，逐光而行，生活不会辜负努力的人",
    ],
    "友情/社交": [
        "同频的人，无论多远，终会相遇；不同频的人，不必强求",
        "社交的本质是舒服，若觉疲惫，不如独处",
        "不必把所有人都请进生命里，留下的，都是宝藏",
        "好的关系，不是互相捆绑，而是彼此成全",
        "你的温柔要留给值得的人，不要浪费在冷漠的人身上",
        "你有拒绝的权利，也有被珍惜的资格",
        "挚友一二，胜过泛泛之交无数",
        "保持边界感，是对自己最好的保护",
    ],
    "生活/趣味": [
        "把温柔留给自己，把光亮留给前路，生活会越来越顺",
        "生活的美好，在于你用心去发现，而不是等待别人给予",
        "哪怕是平凡的日子，也要过得热气腾腾",
        "热爱可抵岁月漫长，心怀热爱，永远年轻",
        "勇敢追梦吧，万一实现了呢？",
        "累了就休息，醒了就奋斗，这才是生活该有的样子",
        "你的生活，由你主宰，别人的意见，仅供参考",
        "每一个清晨，都是新的开始，别辜负了朝阳",
        "平凡的你，也能创造出不平凡的人生",
    ],
    "新年祝福": [
        "新岁启航，愿你眼里有光，脚下有路，心中有梦",
        "新春快乐，愿你所有的遗憾，都是未来惊喜的铺垫",
        "马到成功，愿你每一份努力，都能收获满满的幸福",
        "新的一年，愿你披荆斩棘，活成自己想要的模样",
        "2026，愿你放下过往，轻装上阵，奔赴山海",
        "新年不设限，你的未来，有着无限的可能",
        "新春伊始，愿你跨过山海，终见繁花盛开",
        "新的一年，愿你被世界温柔以待，也能温柔以待世界",
    ],
}

FINAL_BLESSING_TEMPLATE = "{name}，新的一年要一直开心呀"

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
        # [MOD] 独特版：位置分布向中心偏移，越靠中心越容易出现
        center_x = (screen_w - self.width) // 2
        center_y = (screen_h - self.height) // 2
        spread_x = max(120, int(screen_w * 0.24))
        spread_y = max(110, int(screen_h * 0.22))
        x = int(random.gauss(center_x, spread_x))
        y = int(random.gauss(center_y, spread_y))
        x = max(margin, min(x, screen_w - self.width - margin))
        y = max(margin + 36, min(y, screen_h - self.height - margin))
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
        radius = FINAL_CORNER_RADIUS if self.is_final else CORNER_RADIUS

        draw_rounded_rect(
            self.canvas,
            card_x1,
            card_y1,
            card_x2,
            card_y2,
            radius,
            fill=self.theme["bg"],
            outline=self.theme["border"],
            width=2,
        )

        if self.is_final:
            inner_border = mix_hex(self.theme["border"], "#FFFFFF", 0.25)

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

            draw_rounded_rect(
                self.canvas,
                card_x1 + 14,
                card_y1 + 14,
                card_x2 - 14,
                card_y2 - 14,
                FINAL_CORNER_RADIUS - 8,
                fill="",
                outline=inner_border,
                width=1,
            )

            for cx in (38, 58, self.width - 58, self.width - 38):
                self.canvas.create_oval(
                    cx - 3,
                    27 - 3,
                    cx + 3,
                    27 + 3,
                    fill=self.theme["title"],
                    outline="",
                )

            self.canvas.create_text(
                self.width // 2,
                54,
                text=FINAL_HEADER_TEXT,
                fill=self.theme["title"],
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
            inner_border_color = mix_hex(self.theme["border"], "#FFFFFF", 0.35)
            badge_fill = mix_hex(self.theme["accent"], "#FFFFFF", 0.14)
            title_color = self.theme.get("title", self.theme["accent"])

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
                card_x1 + 18,
                card_y1 + 16,
                card_x2 - 18,
                card_y1 + 36,
                10,
                fill=badge_fill,
                outline=self.theme["accent"],
                width=1,
            )

            self.canvas.create_text(
                self.width // 2,
                26,
                text=NORMAL_BADGE_TEXT,
                fill=title_color,
                font=(self.app.font_family, 10, "bold"),
            )

            self.canvas.create_oval(
                card_x1 + 14,
                self.height // 2 - 5,
                card_x1 + 24,
                self.height // 2 + 5,
                fill=self.theme["accent"],
                outline="",
            )
            self.canvas.create_oval(
                card_x2 - 24,
                self.height // 2 - 5,
                card_x2 - 14,
                self.height // 2 + 5,
                fill=self.theme["accent"],
                outline="",
            )

            self.canvas.create_line(
                card_x1 + 24,
                card_y2 - 18,
                card_x2 - 24,
                card_y2 - 18,
                fill=title_color,
                width=1,
            )

            self.canvas.create_text(
                self.width // 2,
                self.height // 2 + 12,
                text=self.text,
                fill=self.theme["text"],
                font=(self.app.font_family, FONT_SIZE_NORMAL, "normal"),
                width=self.width - 56,
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
            text_color = mix_hex(FINAL_THEME["text"], "#A0AEC0", 0.40)
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
            24,
            fill=bg_color,
            outline=border_color,
            width=2,
        )

        draw_rounded_rect(
            self.canvas,
            8,
            8,
            self.width - 9,
            self.height - 9,
            20,
            fill="",
            outline=mix_hex(border_color, "#FFFFFF", 0.30),
            width=1,
        )

        dot_color = mix_hex(border_color, "#FFFFFF", 0.2)
        self.canvas.create_oval(18, 26, 26, 34, fill=dot_color, outline="")
        self.canvas.create_oval(self.width - 27, 26, self.width - 19, 34, fill=dot_color, outline="")

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
