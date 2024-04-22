import os
import pandas as pd
import re

# 设置目录路径
folder_path = os.getcwd()
folder_path = os.path.join(folder_path, '仿真数据2023_10_19')

# 找出所有二级目录
dir_list = []
for root, dirs, files in os.walk(folder_path):
    if root.count(os.sep) == (3+2):
        dir_list.append(root)

# 遍历所有二级目录
for subfolder_path in dir_list:
    files_path = []
    # 遍历所有二级目录
    for root, dirs, files in os.walk(subfolder_path):
        # 找到csv文件并将它们合并为一个dataframe
        for file in files:
            if file.endswith(".csv") and "merged" not in file:
                file_path = os.path.join(root, file)
                files_path.append(file_path)
    files_path.sort()

    df_list = []
    for item_file_path in files_path:
        # 正则表达式 提取相关信息
        period = re.search(r"(?<=周期)\d+(?=s)",item_file_path).group(0)
        angle = re.search(r"(?<=，)\d+(?=°)",item_file_path).group(0)
        wave_height = re.search(r"(?<=波高)\d+(?:\.\d+)?",item_file_path).group(0)
        flow_speed = re.search(r"(?<=流速)\d+(?=节)",item_file_path).group(0)
        # 组合成新的字符串
        new_string = f"{period}_deg{angle}_H{wave_height}_V{flow_speed}knot_"
        # 读取csv文件，并处理
        df = pd.read_csv(item_file_path, encoding='utf-8', skiprows=18)
        selected_rows = df.iloc[300:1801].copy()
        selected_rows.iloc[:, 1:] = selected_rows.iloc[:, 1:] / 1e4
        selected_rows.rename(columns=lambda x: new_string + x, inplace=True)
        max_value = selected_rows.max()
        max_value[new_string + '*Time (s)'] = 'max'
        avg_value = selected_rows.mean()
        avg_value[new_string + '*Time (s)'] = 'avg'
        var_value = selected_rows.var()
        var_value[new_string + '*Time (s)'] = 'var'
        calculate_df = pd.DataFrame([max_value, avg_value, var_value])
        merged_df = pd.concat([selected_rows, calculate_df], axis=0)
        df_list.append(merged_df)
        
    merged_df = pd.concat(df_list, axis=1)

    # 将合并后的dataframe保存为merged.csv
    folder_name = os.path.basename(subfolder_path)
    output_file = os.path.join(subfolder_path, folder_name + "_merged.csv")
    merged_df.to_csv(output_file, index=False)