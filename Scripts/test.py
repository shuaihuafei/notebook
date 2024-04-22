from PIL import Image, ImageDraw, ImageFont

def add_text_to_image(image_path, text, opacity, font_size=20):
    """
    在图像上添加文字，并设置透明度。
    
    :param image_path: 图像的路径
    :param text: 要添加的文字
    :param opacity: 文字的透明度，范围从0（完全透明）到1（完全不透明）
    :param font_size: 字体大小
    """
    # 打开图像
    image = Image.open(image_path)
    draw = ImageDraw.Draw(image)
    
    # 设置字体和大小
    font = ImageFont.truetype("arial.ttf", font_size)  # 使用 Arial 字体，可以替换为其他字体文件
    
    # 计算文字的位置
    text_width, text_height = draw.textsize(text, font=font)
    image_width, image_height = image.size
    x = (image_width - text_width) / 2
    y = (image_height - text_height) / 2
    
    # 设置透明度
    text_opacity = int(255 * opacity)
    fill_color = (255, 0, 0, text_opacity)  # 红色，可调整透明度
    
    # 在图像上添加文字
    draw.text((x, y), text, font=font, fill=fill_color)
    
    # 保存修改后的图像
    image.save("output_image_with_text.png")

# 示例用法
image_path = "2024-04-15_20-27.png"  # 替换为您的图像路径
text = "Danger1"
opacity = 0  # 透明度设置为0.5
font_size = 100  # 字体大小设置为50
add_text_to_image(image_path, text, opacity, font_size)
