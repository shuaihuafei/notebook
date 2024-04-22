############################
## 查找文件大小大于50M的文件
############################
# import os
# def find_large_files(folder_path, size_threshold):
#     large_files = []
#     # 遍历当前目录及其子目录下的所有文件和文件夹
#     for root, dirs, files in os.walk(folder_path):
#         for file_name in files:
#             file_path = os.path.join(root, file_name)
#             file_size = os.path.getsize(file_path) / (1024 * 1024)  # 转换为MB单位
#             if file_size > size_threshold:
#                 large_files.append(file_path)
#     return large_files
# # 替换为实际的文件夹路径和文件大小阈值
# folder_path = './'  # 当前文件夹
# size_threshold = 50  # 50MB
# large_files = find_large_files(folder_path, size_threshold)
# # 输出找到的大文件路径
# for file_path in large_files:
#     print(file_path)


############################
## 查找文件大小大于50M的文件
############################
import re

def replace_date_format(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
        new_content = re.sub(r'\b(\d{4})(\d{2})(\d{2})\b', r'\1.\2.\3', content)
    
    with open(file_path, 'w') as file:
        file.write(new_content)

# 替换指定的md文件
replace_date_format('DayilyNote.md')