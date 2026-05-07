import wordcloud, jieba, matplotlib.pyplot as plt
import numpy as np
from PIL import Image
import os

print("当前目录：", os.getcwd())
print("目录下的文件：", os.listdir())
TEXT_FILE = "我的文本.txt"
IMAGE_FILE = "pipa.png"