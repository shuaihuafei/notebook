# pixhawk2.4.8使用记录
## 烧录固件
### 参考博客
[烧录固件](https://blog.csdn.net/Maker_pace/article/details/118712434)
### 总结步骤
1. 烧录固件可以问卖飞控的淘宝客服直接要
2. 先打开飞控软件，来到固件固件的菜单栏
   ![alt text](.assets_IMG/Pixhawk_note/image.png)
3. 通过USB连接飞控和电脑，会自动跳出右边的菜单栏，然后选择 高级设置 并选择 自定义固件文件 ，然后点击确定，并选择需要安装的固件文件。飞控就会自动安装固件。
   ![alt text](.assets_IMG/Pixhawk_note/image-1.png)
4. 烧录完成后会提示升级完成，稍等几秒，QGC就会跳转到飞控正常使用的界面
   ![alt text](.assets_IMG/Pixhawk_note/image-2.png)
   ![alt text](.assets_IMG/Pixhawk_note/image-3.png)
## 测试pixhawk与MavROS通信
### 参考博客
[测试px4与mavros通信](https://blog.csdn.net/weixin_43296222/article/details/103778476?ops_request_misc=&request_id=&biz_id=102&utm_term=%E6%B5%8B%E8%AF%95px4%E4%B8%8Emavros%E9%80%9A%E8%AE%AF&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-7-103778476.142^v100^pc_search_result_base4&spm=1018.2226.3001.4187)  
[测试px4与mavros通信](https://blog.csdn.net/weixin_65733623/article/details/130695966?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522171297182916800225543502%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=171297182916800225543502&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-2-130695966-null-null.142^v100^pc_search_result_base4&utm_term=mavros&spm=1018.2226.3001.4187)  
[测试apm与mavros通信](https://blog.csdn.net/qq_42994487/article/details/135655473)
### 总结步骤
1. 安装mavros，有两种方式：
   - 二进制安装：
     ```bash
     sudo apt update
     sudo apt install ros-${ROS_DISTRO}-mavros ros-${ROS_DISTRO}-mavros-extras
     # 能成功cd到mavros文件夹中就说明安装成功
     roscd mavros
     ```
   - 源码安装：[Ubuntu 18.04下MAVROS源码安装实战教程](https://cloud.baidu.com/article/3285498) (注：未实践过，可自行百度尝试)
2. 安装GeographicLib(安装这个库，其实也是安装mavros的一部分，之所以单独列出来，是因为这个库的安装可能会有问题)，两种安装方式：
   - 官网安装(安装前提是要科学上网，并且安装过程很慢，在安装过程中会好像卡住，其实是正在安装，静候即可)：
     ```bash
     wget https://raw.githubusercontent.com/mavlink/mavros/master/mavros/scripts/install_geographiclib_datasets.sh
     sudo chmod 777 ./install_geographiclib_datasets.sh
     # 执行下面的安装脚本会自动安装到/usr/share路径下
     sudo ./install_geographiclib_datasets.sh
     ```
   - 从已经安装好的电脑上复制过去
     ```bash
     # 先提升到root用户
     sudo su
     # scp远程复制
     scp -r shuai@192.168.1.xxx:/usr/share/GeographicLib /usr/share
     ```
3. 将Pixhawk通过USB连接到电脑，打开QGC地面站(这里注意串口都是使用的pixhawk2.4.8上的TELEM 2)
   - PX4设置以下参数(一开始参数里可能只有MAV_1_CONFIG，而搜不到另外两个参数，只需要先把MAV_1_CONFIG设置为TELEM 2，然后把飞控重启后就有了):
     - MAV_1_CONFIG= TELEM 2
     - MAV_1_MODE = Onboard
     - SER_TEL2_BAUD = 921600 8N1
   - APM设置以下参数:
     - SERIAL2_BAUD = 921600（如果通信失败则适当降低波特率为 460800）
     - SERIAL2_PROTOCOL = MAVLink2
4. 硬件连接，连接TELEM 2与板载计算机串口(参考：[青云硬件电路图](https://qingyun-docs.readthedocs.io/zh/latest/01%E7%A1%AC%E4%BB%B6%E4%BB%8B%E7%BB%8D.html))
   pixhawk2.4.8上TELEM 2口引脚图：  
   ![alt text](.assets_IMG/Pixhawk_note/image-6.png)  
   青云1000串口位置图(这里只有青云左下角的那个可以用)(串口0，仅用于输出青云1000的启动日志，用户不应占用此串口。串口1，是全功能串口，用户可以使用此串口收发数据。该串口对应的设备名称为`/dev/ttyAMA1`)：  
   ![alt text](.assets_IMG/Pixhawk_note/image-7.png)  
   ![alt text](.assets_IMG/Pixhawk_note/image-9.png)  
   - USB转TTL(可以通过插拔USB前后分别执行`ls /dev`来观察是哪个USB串口在使用)：
     ![alt text](.assets_IMG/Pixhawk_note/image-5.png)
   - UART串口(串口设备是固定的`/dev/ttyAMA1`)：
     ![alt text](.assets_IMG/Pixhawk_note/image-4.png)
5. 启动launch文件apm.launch（如果用的 PX4 固件则对应 px4.launch），测试与Pixhawk板的通讯。
   ```bash
   # 下面的ttyAMA1可以替换成ttyUSB0，具体看实际哪种硬件连接方式
   # 串口波特率的设置需要与之前QGC中设置的参数一样
   sudo chmod 777 /dev/ttyAMA1
   roslaunch mavros apm.launch fcu_url:=/dev/ttyAMA1:921600
   ```
   launch文件启动后，出现下面的字样，就说明板载计算机与飞控可以进行通讯  
   ![alt text](.assets_IMG/Pixhawk_note/image-11.png)  
   ```bash
   # 另起一个终端，测试 NUC 订阅 Pixhawk 中的 IMU 发布频率信息
   rostopic hz /mavros/imu/data_raw
   ```

## 板载计算机4G模块通信
### 参考博客
[手把手教你打造自己的4G数传模块](https://blog.csdn.net/weixin_43053387/article/details/103026843?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522171395645816800211587350%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=171395645816800211587350&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-3-103026843-null-null.142^v100^pc_search_result_base1&utm_term=%E9%A3%9E%E6%8E%A7%204G%E6%A8%A1%E5%9D%97&spm=1018.2226.3001.4187)  
[阿木实验室4G异地控制](https://docs.amovlab.com/nywiki/#/zh-cn/4G%E5%BC%82%E5%9C%B0%E6%8E%A7%E5%88%B6)  

## 校准电调
买飞控的淘宝商家提供的视频教程
1. 遥控器打开，油门推最大，飞机上电
2. 飞控指示灯红黄蓝交替闪，此时飞机断电
3. 飞机再上电，打开安全开关，安全开关常亮，飞机此时会滴滴两声，油门拉最低
4. 此时电调滴的一声，完成校准
5. 飞机断电再上电，此时指示灯经过一段时间后变成蓝灯闪烁

## 乐迪遥控器
1. 左手油门：基础菜单->系统设置->摇杆模式->2

## 参数设置
1. SERIAL1_BAUD=57600 否则无线wifi会断连