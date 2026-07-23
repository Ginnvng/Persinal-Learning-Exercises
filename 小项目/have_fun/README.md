# have_fun 祝福弹窗（现代视觉版）

## 文件结构

```text
小玩意/have_fun/
├─ main.pyw      # 主程序（双击可运行）
└─ README.md     # 说明文档
```

## 运行环境

- Windows 10/11（优先）
- Python 3.9+
- 依赖：`customtkinter`（新增）

## 推荐安装方式（虚拟环境）

```powershell
cd C:\Study\Code
py -3 -m venv environment
Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass
.\environment\Scripts\Activate.ps1
python -m pip install -U pip
python -m pip install customtkinter pyinstaller
```

## 依赖验证

```powershell
python -c "import customtkinter as ctk; print(ctk.__version__)"
python -m PyInstaller --version
```

## 运行程序

```powershell
cd C:\Study\Code\Persinal-Learning-Exercises\小玩意\have_fun
python .\main.pyw
```

也可以直接双击 `main.pyw` 运行。

## 打包成 Windows `.exe`

```powershell
cd C:\Study\Code\Persinal-Learning-Exercises\小玩意\have_fun
python -m PyInstaller --noconfirm --onefile --windowed --name 祝福弹窗 main.pyw
```

生成文件：`dist\祝福弹窗.exe`

## 核心功能（保持不变）

- 通过 `NAME = "..."` 修改名字，无需运行时输入
- 祝福语分“可绑定姓名 / 无需绑定姓名”两类随机展示
- 自动弹窗 + 15秒后分阶段收尾（5 -> 3 -> 1 -> 收尾祝福）
- 右上角“停止祝福”按钮可手动触发收尾逻辑

## 新视觉与动画设计

- 现代扁平风弹窗，圆角默认 `12px`
- 莫兰迪低饱和配色（如 `#F8F9FA / #E8F4F8 / #FDF2F8`）
- 柔和阴影：`2px` 偏移，近似 `8px` 模糊观感，约 `20%` 透明度
- 出现动画：`300ms`，`0.9x+20%透明` -> `1.0x+100%透明`（ease-in-out）
- 消失动画：`500ms`，`1.0x+100%透明` -> `1.1x+0%透明`（ease-in-out）
- 上浮动画：每帧上移 `2px`

## Windows 毛玻璃兼容说明

- 程序会优先尝试 Windows 原生 Acrylic/BlurBehind。
- 若当前系统或 API 不支持，会自动降级为半透明莫兰迪卡片。
- 降级不影响主逻辑和收尾逻辑。

## 参数微调指南（都在 `main.pyw` 顶部）

### 1) 名字

- `NAME = "张泉奕"`

### 2) 视觉

- `CORNER_RADIUS_PX`：圆角
- `GLASS_COLOR_PALETTE`：弹窗配色池
- `TEXT_COLOR_PRIMARY` / `TEXT_COLOR_SECONDARY`：文字颜色
- `SHADOW_OFFSET_PX` / `SHADOW_OPACITY` / `SHADOW_BLUR_HINT`：阴影观感

### 3) 字体

- `FONT_SIZE_MIN` / `FONT_SIZE_MAX`：字号范围
- `LINE_HEIGHT_MULTIPLIER`：行高倍率
- `WINDOWS_FONT_CANDIDATES` / `MAC_FONT_CANDIDATES` / `LINUX_FONT_CANDIDATES`：字体候选

### 4) 动画

- `APPEAR_DURATION_MS`：出现时长
- `DISMISS_DURATION_MS`：消失时长
- `ANIM_FPS`：动画帧率
- `FLOAT_UP_PX_PER_FRAME`：每帧上浮像素
- `APPEAR_START_SCALE` / `APPEAR_START_ALPHA` / `DISMISS_END_SCALE`：缩放与透明度起止

### 5) 结束流程

- `AUTO_WINDDOWN_AFTER_SEC`
- `WINDDOWN_STAGE_1_SEC`
- `WINDDOWN_STAGE_2_SEC`
- `WINDDOWN_STAGE_3_SEC`

## 祝福语分区说明

- 可绑定姓名：`BINDABLE_BLESSINGS`
- 无需绑定姓名：`GENERIC_BLESSINGS`
- 收尾文案：`FINAL_BLESSING_TEMPLATE`

可直接在对应数组里增删替换文案，主逻辑会自动生效。
