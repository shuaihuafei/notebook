import os
import shutil
from PIL import Image, ImageDraw, ImageFont

# 原始图片文件夹路径和水印图片文件夹路径
original_folder = "images"
watermarked_folder = "images_watermarked_folder"

# 创建水印图片文件夹
if not os.path.exists(watermarked_folder):
    os.makedirs(watermarked_folder)

# 设置水印文本
watermark_text = "帅华飞231110201217"

# 遍历原始图片文件夹中的所有图片
for filename in os.listdir(original_folder):
    if filename.endswith(".jpg") or filename.endswith(".png"):
        # 打开原始图片
        img = Image.open(os.path.join(original_folder, filename))

        # 在图片上创建Draw对象
        draw = ImageDraw.Draw(img)

        # 设置字体
        font = ImageFont.truetype("arial.ttf", 36)

        # 获取图片的宽度和高度
        width, height = img.size

        # 添加水印
        textwidth, textheight = draw.textsize(watermark_text, font)
        x = width - textwidth - 10
        y = height - textheight - 10
        draw.text((x, y), watermark_text, font=font)

        # 保存修改后的图片到水印图片文件夹
        watermarked_path = os.path.join(watermarked_folder, filename)
        img.save(watermarked_path)

# 打印完成消息
print("水印添加完成！")
