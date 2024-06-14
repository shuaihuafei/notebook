import pandas as pd
import numpy as np

# 创建一个包含无人机参数的数据集
np.random.seed(0)  # 确保每次生成的数据一致

# 生成1000组无人机数据
num_drones = 1000
speed = np.random.uniform(20, 100, num_drones)  # 飞行速度
altitude = np.random.uniform(100, 500, num_drones)  # 飞行高度
battery = np.random.uniform(20, 100, num_drones)  # 电池电量
temperature = np.random.uniform(0, 50, num_drones)  # 发动机温度

# 创建数据框
df_1000 = pd.DataFrame({
    'Speed': speed,
    'Altitude': altitude,
    'Battery': battery,
    'Temperature': temperature
})

# 标记故障
df_1000['Fault'] = np.where((df_1000['Speed'] < 30) | (df_1000['Temperature'] > 40), 1, 0)

# 保存为CSV文件
csv_file_path = './Scripts/drone_data.csv'
df_1000.to_csv(csv_file_path, index=False)