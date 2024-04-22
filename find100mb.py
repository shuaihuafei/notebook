import os

def find_large_files(folder_path, min_size):
    # 遍历文件夹及其子文件夹
    for root, dirs, files in os.walk(folder_path):
        for file_name in files:
            file_path = os.path.join(root, file_name)
            # 获取文件大小（以字节为单位）
            file_size = os.path.getsize(file_path)
            # 将字节转换为MB并判断是否大于指定大小
            if file_size > min_size:
                # 打印路径
                print("File:", file_path, "Size:", file_size / (1024 * 1024), "MB")

# 文件夹路径
folder_path = "your_folder_path"
# 最小文件大小（以字节为单位）
min_size = 100 * 1024 * 1024  # 100MB

# 调用函数查找大于100MB的文件
find_large_files(folder_path, min_size)
