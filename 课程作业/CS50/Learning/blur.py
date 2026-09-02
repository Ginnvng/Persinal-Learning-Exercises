from PIL import Image,ImageFilter
before = Image.open("/mnt/c/Users/DQDLY/Pictures/Saved Pictures/b.png")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("/mnt/c/Users/DQDLY/Desktop/王艳是个大傻逼.png")