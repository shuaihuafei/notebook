# 教程一 台交通大学无人机系列课程——2运动数学（欧拉角、四元数、坐标系转换）  
B站教程链接：[运动数学（欧拉角、四元数、坐标系转换）](https://www.bilibili.com/video/BV1z94y1Y7g8/?spm_id_from=333.337.search-card.all.click&vd_source=a5f4029436fab3ad44f642e3a69eb1d1)
# 目录
![picture 2](.assets_IMG/Quaternions/IMG_20230811-134721389.png)  
# 坐标系
![picture 3](.assets_IMG/Quaternions/IMG_20230811-135050266.png)  
![picture 4](.assets_IMG/Quaternions/IMG_20230811-135124165.png)  
![picture 9](.assets_IMG/Quaternions/IMG_20230811-135543779.png)  
![picture 10](.assets_IMG/Quaternions/IMG_20230811-135800413.png)  
![picture 11](.assets_IMG/Quaternions/IMG_20230811-184830804.png)  
![picture 12](.assets_IMG/Quaternions/IMG_20230811-184943073.png)  
# 旋转矩阵
![picture 13](.assets_IMG/Quaternions/IMG_20230811-185242161.png)  
![picture 14](.assets_IMG/Quaternions/IMG_20230811-185324524.png)  
![picture 15](.assets_IMG/Quaternions/IMG_20230811-185341328.png)  
![picture 17](.assets_IMG/Quaternions/IMG_20230811-185522806.png)  
![picture 18](.assets_IMG/Quaternions/IMG_20230811-185632669.png)  
![picture 19](.assets_IMG/Quaternions/IMG_20230813-104345673.png)  
![picture 20](.assets_IMG/Quaternions/IMG_20230813-104638190.png)  
![picture 21](.assets_IMG/Quaternions/IMG_20230813-104956745.png)  
![picture 22](.assets_IMG/Quaternions/IMG_20230813-105213228.png)  
![picture 23](.assets_IMG/Quaternions/IMG_20230813-105731567.png)  
![picture 24](.assets_IMG/Quaternions/IMG_20230813-110157809.png)  
![picture 25](.assets_IMG/Quaternions/IMG_20230813-110248893.png)  
![picture 26](.assets_IMG/Quaternions/IMG_20230813-111900764.png)  
![picture 27](.assets_IMG/Quaternions/IMG_20230813-112006960.png)  
![picture 28](.assets_IMG/Quaternions/IMG_20230813-112102307.png)  
```
注意：这里的Body-Fixed Rotation就是之前的Euler Angles，Space-Fixed Rotation就是之前的Fixed Angles
```
![picture 29](.assets_IMG/Quaternions/IMG_20230813-112517910.png)  
![picture 30](.assets_IMG/Quaternions/IMG_20230813-113458799.png)  
# 欧拉角
![picture 31](.assets_IMG/Quaternions/IMG_20230813-113945004.png)  
![picture 32](.assets_IMG/Quaternions/IMG_20230813-143028745.png)  
![picture 33](.assets_IMG/Quaternions/IMG_20230813-143303569.png)  
![picture 34](.assets_IMG/Quaternions/IMG_20230813-143618757.png)  
![picture 35](.assets_IMG/Quaternions/IMG_20230813-153755152.png)  
# 变换矩阵
![picture 36](.assets_IMG/Quaternions/IMG_20230813-153812659.png)  
![picture 37](.assets_IMG/Quaternions/IMG_20230813-153906611.png)  
![picture 38](.assets_IMG/Quaternions/IMG_20230813-154219835.png)  
![picture 39](.assets_IMG/Quaternions/IMG_20230813-154517619.png)  
![picture 40](.assets_IMG/Quaternions/IMG_20230813-154834298.png)  
![picture 41](.assets_IMG/Quaternions/IMG_20230813-155003837.png)  
![picture 42](.assets_IMG/Quaternions/IMG_20230813-155431684.png)  
![picture 43](.assets_IMG/Quaternions/IMG_20230813-155722997.png)  
![picture 44](.assets_IMG/Quaternions/IMG_20230813-155856998.png)  
![picture 45](.assets_IMG/Quaternions/IMG_20230813-160047164.png)  
![picture 46](.assets_IMG/Quaternions/IMG_20230813-161925644.png)  
![picture 47](.assets_IMG/Quaternions/IMG_20230813-162554524.png)  
![picture 48](.assets_IMG/Quaternions/IMG_20230813-162655617.png)  
# 四元数
![picture 49](.assets_IMG/Quaternions/IMG_20230813-162730043.png)  
![picture 50](.assets_IMG/Quaternions/IMG_20230813-165226593.png)  
![picture 51](.assets_IMG/Quaternions/IMG_20230813-165431998.png)  
![picture 52](.assets_IMG/Quaternions/IMG_20230813-165510670.png)  
![picture 53](.assets_IMG/Quaternions/IMG_20230813-165711527.png)  
```
Hamilton product有点像乘法分配律，交叉相乘后再求和。
```
![picture 63](.assets_IMG/Quaternions/IMG_20230816-113804883.png)  
![picture 54](.assets_IMG/Quaternions/IMG_20230813-170633965.png)  
![picture 56](.assets_IMG/Quaternions/IMG_20230813-171115597.png)  
## 用四元数转动向量
![picture 57](.assets_IMG/Quaternions/IMG_20230813-171246854.png)  
```
这里是将四元数转化为旋转矩阵的公式
```
![picture 58](.assets_IMG/Quaternions/IMG_20230813-171455114.png)  
![picture 59](.assets_IMG/Quaternions/IMG_20230813-172213388.png)  
## 用四元数转动坐标系
可以发现其旋转公式与向量转动正好相反。这个与之前用矩阵旋转是一样的，向量旋转$\theta$就相当于矩阵旋转$-\theta$  
![picture 60](.assets_IMG/Quaternions/IMG_20230813-172356474.png)  
![picture 61](.assets_IMG/Quaternions/IMG_20230816-111622182.png)  
```
这个案例是关于无人机的可看可不看
```
![picture 62](.assets_IMG/Quaternions/IMG_20230816-112319760.png)  
![picture 64](.assets_IMG/Quaternions/IMG_20230816-114134906.png)  
![picture 72](.assets_IMG/Quaternions/IMG_20230816-122547296.png)  
![picture 66](.assets_IMG/Quaternions/IMG_20230816-114505667.png)  
```
下图中的第一个公式是根据上图中的对应关系，表示四元数与旋转矩阵中各个旋转角的关系。第二个公式则与四元数无关，仅仅表示旋转矩阵中的各个值与旋转角的关系。
```
![picture 67](.assets_IMG/Quaternions/IMG_20230816-115428810.png)  
![picture 68](.assets_IMG/Quaternions/IMG_20230816-121724088.png)  
![picture 69](.assets_IMG/Quaternions/IMG_20230816-121744178.png)  
![picture 70](.assets_IMG/Quaternions/IMG_20230816-121753968.png)  
![picture 71](.assets_IMG/Quaternions/IMG_20230816-121826672.png)  
