import pandas as pd
from scipy.stats import shapiro
from scipy.stats import kurtosistest

# 读取Excel文件
df = pd.read_excel('新的数据.xlsx', sheet_name=None)

# 创建ExcelWriter对象
writer = pd.ExcelWriter('output.xlsx')

# 遍历所有的sheet
for sheet_name in df:
    result_df = []
    # 判断时间字段所在的列索引（假设时间字段在第一列）
    time_column_index = 0
    
    # 将时间字段转换为数值类型
    df[sheet_name].iloc[:, time_column_index] = pd.to_numeric(df[sheet_name].iloc[:, time_column_index], errors='coerce')
    
    # 获取每个sheet中时间字段从200到最后的数据
    selected_rows = df[sheet_name][df[sheet_name].iloc[:, time_column_index] >= 200]
    
    selected_data_1_3 = selected_rows.iloc[:, 1:4]
    selected_data_4 = selected_rows.iloc[:, 4:]
    
    # 计算最大值、最小值和差的绝对值
    max_value_1_3 = selected_data_1_3.max()
    min_value_1_3 = selected_data_1_3.min()
    abs_diff_1_3 = (max_value_1_3 - min_value_1_3).abs()

    # 计算最大值、均值和方差
    max_value_4 = selected_data_4.max()/1e4
    mean_value_4 = selected_data_4.mean()/1e4
    variance_value_4 = selected_data_4.var()/1e8

    # 创建结果DataFrame
    # 注意：在创建DataFrame时，如果不指定index，是会自动创建的，并且是从0开始递增
    result_df_0 = pd.DataFrame(data=['Max/Max','Min/Mean','Abs/Variance'], 
                               columns = ['时间'])

    # 创建结果DataFrame（列名为Max、Min、Abs）
    # result_df_1_3 = pd.DataFrame({'Max': max_value_1_3, 'Min': min_value_1_3, 'Abs': abs_diff_1_3})
    result_df_1_3 = pd.DataFrame(data=[max_value_1_3, min_value_1_3, abs_diff_1_3])

    # 创建结果DataFrame（列名为Max、Mean、Variance）
    # result_df_4 = pd.DataFrame({'Max': max_value_4, 'Mean': mean_value_4, 'Variance': variance_value_4})
    result_df_4 = pd.DataFrame(data=[max_value_4, mean_value_4, variance_value_4])

    # 将结果DataFrame添加到列表中
    result_df.append(result_df_0)
    result_df.append(result_df_1_3)
    result_df.append(result_df_4)

    # 横向拼接每个sheet的结果DataFrame
    result_df_concat_1_2_3 = pd.concat(result_df, axis=1)

    for col_name, column in selected_data_4.iteritems():
        stat, p = kurtosistest(column)
        alpha = 0.05
        
        if p > alpha:
            print(f'列 {col_name} 在 {sheet_name} 中符合分布')
        else:
            print(f'列 {col_name} 在 {sheet_name} 中不符合分布')
    result_df_concat = pd.concat([df[sheet_name], result_df_concat_1_2_3], axis=0)

    # 将结果DataFrame写入ExcelWriter对象对应的sheet中
    result_df_concat.to_excel(writer, sheet_name=sheet_name, index=False)

# 保存ExcelWriter对象为文件
writer.close()