from PIL import Image,ImageFilter
before = Image.open("/mnt/c/Users/DQDLY/Desktop/王洁.png")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("/mnt/c/Users/DQDLY/Desktop/王车车.png")