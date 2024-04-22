import difflib

def compare_files(file1, file2):
    # 打开文件并读取内容
    with open(file1, 'r') as f1:
        file1_text = f1.read()

    with open(file2, 'r') as f2:
        file2_text = f2.read()

    # 比较两个文件并输出差异
    diff = difflib.ndiff(file1_text.splitlines(), file2_text.splitlines())
    for line in diff:
        print(line)

# 调用函数比较文件差异
compare_files('/home/shuai/视频/改变布置方式后/merged-改变布置方式后.csv', '/home/shuai/视频/改变布置方式后/merged-改变布置方式后0.csv')
