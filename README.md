# Personal-learning-exercises

This repository is for learning programming.

It may contain messy or suboptimal code.
Suggestions and improvements are very welcome.

## 目录结构

按“代码从哪来”分成 4 类：

| 目录 | 内容 |
| --- | --- |
| `学校课程/` | 学校布置的作业和实验 |
| `算法训练/` | 集训和各 OJ 平台刷题 |
| `自学/` | 自己学的网课和教材 |
| `小项目/` | 自己想做的小程序 |

拿不准放哪时：老师布置的 → `学校课程`；做题 → `算法训练`；自己跟着课学 → `自学`；自己想做的东西 → `小项目`。

### `学校课程/`

- 命名：`学期-课程名`，如 `大一上-C语言/`、`大二上-Java/`、`大二上-数据结构/`。
- 里面按老师的安排分，如 `实验1/`、`实验2/`，或按日期分。
- `大二上-Java/` 是一个 IntelliJ 项目，每次作业是 `src/` 下的一个包，按日期命名，如 `hw26_09_08`。新作业：在 `src` 上右键 → New → Package。

### `算法训练/`

- `集训/`：寒暑假集训，按届分，如 `2026寒假/`、`2026暑假/`，里面再分训练题和训练赛。
- `刷题/`：各 OJ 平台的刷题和比赛，按平台分，如 `nowcoder/`、`PTA/`；新平台就新建文件夹，如 `LeetCode/`、`洛谷/`。
- 一道题一个文件，命名 `题号_题目名.cpp`，如 `A_热辣滚烫.cpp`。

### `自学/`

- 用课程名命名，如 `CS50/`、`数据结构-浙大MOOC/`。
- 里面按章节分，加编号前缀保证顺序，如 `01-线性表/`、`02-栈和队列/`。
- Python 依赖记在 `requirements.txt`，虚拟环境 `myenv/` 不提交。换电脑后重建：

  ```bash
  python3 -m venv myenv && myenv/bin/pip install -r requirements.txt
  ```

### `小项目/`

- 不是作业也不是刷题，自己想做的东西，如 `have_fun/`（祝福弹窗）、`文本编辑器.cpp`。
- 稍大的项目单独建一个文件夹。

## 配置文件

- `.gitignore`：自动忽略编译产物（Linux 下无扩展名的可执行文件、`.exe`、`.class` 等）、Python 虚拟环境和 IDE 配置。新建需要提交的无扩展名文件时，要在 `.gitignore` 里单独放行（`Makefile`、`LICENSE` 已放行）。
- `.vscode/settings.json`：保存时自动格式化 C/C++，风格为 Microsoft 基础 + Allman 大括号 + 4 空格缩进 + 数组按列右对齐（二维数组会自动展开成竖排并按列对齐）。
- `.vscode/tasks.json`：g++ 编译当前文件的任务。
- `.clang-format`：目前未被 VS Code 使用，实际格式以 `settings.json` 为准。
