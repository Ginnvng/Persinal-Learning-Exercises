from PIL import Image,ImageFilter
before = Image.open("/mnt/c/Users/DQDLY/Pictures/Saved Pictures/b.png")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("/mnt/c/Users/DQDLY/Desktop/Yolo is SB.png")