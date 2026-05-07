import wordcloud, jieba, matplotlib.pyplot as plt
import numpy as np
from PIL import Image
import os
import chardet

print("当前目录：", os.getcwd())
print("目录下的文件：", os.listdir())
TEXT_FILE = "我的文本.txt"        # 同一目录
IMAGE_FILE = "pipa.png"

# 检查文件
if not os.path.exists('pipa.png'):
    print(" 找不到 pipa.png")
if not os.path.exists('我的文本.txt'):
    print(" 找不到 我的文本.txt")

# 检查字体
font_path = 'C:/Windows/Fonts/simhei.ttf'
if not os.path.exists(font_path):
    print(f" 找不到字体：{font_path}")
    # 尝试其他字体
    test_fonts = ['C:/Windows/Fonts/msyh.ttc', 'C:/Windows/Fonts/simsun.ttc']
    for f in test_fonts:
        if os.path.exists(f):
            font_path = f
            print(f" 改用字体：{f}")
            break

text = None
encodings_to_try = ['gbk', 'utf-8']

# 首先用 chardet 检测编码，放到最前面尝试
try:
    with open(TEXT_FILE, 'rb') as f:
        raw = f.read()
        detected = chardet.detect(raw)['encoding']
        if detected:
            encodings_to_try.insert(0, detected)  # 把最可能的编码排第一位
except:
    pass  # 如果检测失败，仍然使用预设的 gbk 和 utf-8

# 按顺序尝试所有编码
for enc in encodings_to_try:
    try:
        with open(TEXT_FILE, encoding=enc) as f:
            text = f.read()
        print(f"使用编码 {enc} 读取成功，长度：{len(text)}")
        break  # 成功后跳出循环
    except (UnicodeDecodeError, LookupError):
        continue  # 编码不对就试下一个

if text is None:
    print("所有编码尝试失败，请将文本文件另存为 UTF-8 或 GBK 编码")
    exit(1)

try:
    # 测试读取文本
    with open('我的文本.txt', encoding='UTF-8') as f:
        text = f.read()
    print(f" 读取文本成功，长度：{len(text)}")
    
    # 测试分词
    words = ' '.join(jieba.cut(text))
    print(f"分词成功，词数：{len(words.split())}")
    
    # 测试加载图片
    img = Image.open('pipa.png')
    mask = np.array(img.convert('L'))
    print(f"加载图片成功，尺寸：{img.size}")
    
    # 生成词云
    wc = wordcloud.WordCloud(
        font_path=font_path,
        mask=mask,
        background_color='white',
        max_words=150,
        colormap='OrRd'
    ).generate(words)
    print("词云生成成功")
    
    # 保存
    wc.to_file('词云结果.png')
    print(" 保存成功")
    
    # 显示
    plt.figure(figsize=(10, 8))
    plt.imshow(wc, interpolation='bilinear')
    plt.axis('off')
    plt.show()
    print("成功生成词云！")
    
except FileNotFoundError as e:
    print(f" 文件找不到：{e}")
except UnicodeDecodeError:
    print(" 编码错误，尝试其他编码...")
    try:
        # 尝试 utf-8
        with open('我的文本.txt', encoding='utf-8') as f:
            text = f.read()
        print(" 使用 utf-8 编码成功")
        # 继续执行...
    except:
        print(" 请将文本文件另存为 ANSI 或 UTF-8 编码")
except Exception as e:
    print(f"出错：{e}")
    print(f"错误类型：{type(e).__name__}")
import chardet
with open('我的文本.txt', 'rb') as f:
    encoding = chardet.detect(f.read())['encoding']
with open('我的文本.txt', encoding=encoding) as f:
    text = f.read()
