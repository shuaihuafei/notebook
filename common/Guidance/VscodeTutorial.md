# 如何在Vscode中调试
## 教程
- [基于VSCode和CMake实现C/C++开发 | Linux篇(之前主要是看了22和23节)](https://www.bilibili.com/video/BV1fy4y1b7TC?p=22&vd_source=a5f4029436fab3ad44f642e3a69eb1d1)
## 概述
1. 点击旁边调试按钮，添加`launch.json`文件。
![picture 1](.assets_IMG/VscodeTutorial/IMG_20231129-161610172.png)  
2. 选择`Cmake Debugger`。
![picture 2](.assets_IMG/VscodeTutorial/IMG_20231129-161706872.png)  
3. 点击右下角的`add configuration`，再点击`gdb启动`
![picture 3](.assets_IMG/VscodeTutorial/IMG_20231129-161842273.png)  
4. 修改该json文件中的program对应值为cmake生成的可执行文件，如下图：
![picture 0](.assets_IMG/VscodeTutorial/IMG_20231129-161302725.png)  
其中变量`${workspaceFolder}`表示的当前最顶层工程目录所在的路径；`${fileDirname}`表示的是在按F5调试时，当前文件所在的路径。
5. 如果之前配置过`task.json`中的`label`，并且在`launch.json`下方有`"preLaunchTask": "sudo_gdb"`，此时如果按F5调试总是提示task出错，就将此行注释掉，如下图：(注意tasks.json文件与launch.json文件的联动就是通过`"preLaunchTask"`来实现的)  
   ![alt text](.assets_IMG/VscodeTutorial/image-1.png)  
6. 回到之前构建的项目中，在`CMakeLists.txt`文件中添加`set(CMAKE_BUILD_TYPE Debug)`，并且做好在`project`之前添加，这样`cmake .. && make`生成的可执行文件才能被调试，如图：
![picture 4](.assets_IMG/VscodeTutorial/IMG_20231129-162502069.png)  
7. 转到需要调试的cpp文件，在项目目录的`build`文件夹下执行`cmake .. && make`命令后，按`F5`进行调试。
![picture 5](.assets_IMG/VscodeTutorial/IMG_20231129-162854238.png)  
## 注意
通过这种方式调试，同样是适用于嵌套的CMake。只需要在子节点CMakeLists.txt文件中添加`set(CMAKE_BUILD_TYPE Debug)`指令即可。

# 如何关闭Vscode的语法检查报错
## 博客
[如何关闭 C/C++ 插件的错误提示(在这个博客的最下面可以看到)](https://discuss.em-ide.com/d/289-keil)
## 记录步骤
为`当前用户`关闭错误提示：打开 VsCode 设置，搜索：`C_Cpp.errorSquiggles`，将其值设置为：`Disabled`  
![alt text](.assets_IMG/VscodeTutorial/image.png)  

# Vscode的使用技巧
## 博客
[vsCode中如何根据屏幕宽度自动换行](https://blog.csdn.net/weixin_42689147/article/details/87366004)  
