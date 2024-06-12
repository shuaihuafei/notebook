import os
import pandas as pd

def rename_folder(folder_path):
    folders_to_rename = []  # 存储需要重命名的文件夹路径
    for root, dirs, files in os.walk(folder_path):
        for dir_name in dirs:
            if dir_name.startswith('group') and len(dir_name) == 6:
                folders_to_rename.append(os.path.join(root, dir_name))

    for old_dir_name in folders_to_rename:
        new_dir_name = old_dir_name[:-1] + '0' + old_dir_name[-1]  # 构造新的文件夹名字
        os.rename(old_dir_name, new_dir_name)

def rename_files(folder_path):
    files_to_rename = []  # 存储需要重命名的文件路径
    for root, dirs, files in os.walk(folder_path):
        for file_name in files:
            if 'cable' in file_name and len(file_name) > 5:
                dot_index = file_name.rfind('.')
                name = file_name[:dot_index]
                extension = file_name[dot_index:]
                if len(name) == 6:
                    files_to_rename.append((os.path.join(root, file_name), os.path.join(root, name[:5] + '0' + name[5:] + extension)))

    for old_path, new_path in files_to_rename:
        os.rename(old_path, new_path)
        
def process_csv_files(folder_path, x, y):
    data = []
    header = None
    files_path = []
    
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if "cable" in file and file.endswith('.CSV'):
                file_path = os.path.join(root, file)
                files_path.append(file_path)

    files_path.sort()

    for item_file_path in files_path:
        # 提取文件名中的 "group7" 和 "cable7"
        head_tail = os.path.split(item_file_path)
        group = head_tail[0].split('/')[-1]
        cable = head_tail[1].split('.')[0]

        # 将 "group7" 和 "cable7" 与 "id" 拼接成新的字符串
        custom_id = f"id_{group}_{cable}"
        
        df = pd.read_csv(item_file_path, encoding='utf-8', skiprows=5)  # 读取 csv 文件，跳过前5行

        # 重命名字段为 "id" 和 "data"
        df.rename(columns={'Time(seconds)                          ': custom_id, 'Newtons                                 ': 'value'}, inplace=True)

        # 提取需要的行数据，跳过不在范围内的行
        selected_rows = df.iloc[x:y+1]

        if not header:
            header = df.columns.tolist()  # 获取表头

        # 计算最大值和平均值
        max_value = selected_rows.max()/10000
        avg_value = selected_rows.mean()/10000

        # 检查是否存在大于50000的数值
        has_gt_5t = (selected_rows['value'] > 50000).any()
        has_gt_5t_df = pd.DataFrame(data=[['has_gt_5t',has_gt_5t]],
                                    columns = [custom_id,'value'])
        headline_df = pd.DataFrame(data=[['',custom_id]],
                                    columns = [custom_id,'value'])

        # 修改 id 列的值为字符串 "max" 和 "avg"
        max_value[custom_id] = 'max'
        avg_value[custom_id] = 'avg'

        # 将 selected_rows、max_value 和 avg_value 合并为一个 DataFrame
        merged_df = pd.concat([selected_rows, pd.DataFrame({'Max Value': max_value, 'Avg Value': avg_value}).T, has_gt_5t_df, headline_df], axis=0)

        data.append(merged_df)  # 将合并后的 DataFrame 添加到结果列表中
    
    merged_df = pd.concat(data, axis=1)  # 横向拼接所有数据
    
    # 获取文件夹名称
    folder_name = os.path.basename(folder_path)
    output_file = os.path.join(folder_path, 'merged-' + folder_name + '.csv')
    merged_df.to_csv(output_file, index=False, encoding='utf-8')  # 将结果保存为新的 csv 文件
    
    print(f"合并后的文件已保存为 {output_file}")

# 获取当前文件夹路径
folder_path = os.getcwd()
folder_path = os.path.join(folder_path, '无横缆情况')
x = 300  # 起始行
y = 800  # 结束行
rename_folder(folder_path)
rename_files(folder_path)
process_csv_files(folder_path, x, y)  # 处理 csv 文件并合并
