# Linux如何卸载QtCreator
1. 首先通过指令`sudo find / -name qtcreator 2>/dev/null`找到qtcreator的安装目录
2. 进入qtcreator的安装目录，执行卸载指令`sudo ./QtCreatorUninstaller`
## 参考
[ubuntu18.04 LTS卸载qtcreator-10.0.2](https://blog.csdn.net/lyc_daniel/article/details/133858141)

# Linux安装Qt5.12.9的注意事项
[文档教程](./【正点原子】I.MX6U嵌入式Qt开发指南V1.1.pdf)可以参考`【正点原子】I.MX6U嵌入式Qt开发指南V1.1.pdf`的第52页  
[视频教程](https://www.bilibili.com/video/BV1g24y1F7X4)安装主要看下第4和5讲即可  
1. 安装后如果在左下角总菜单中找不到QtCreator，可以通过命令行运行脚本`/opt/Qt5.12.9/Tools/QtCreator/bin/qtcreator.sh &`，在后台打开QtCreator
2. 安装后如果QtCreator中无法输入中文  
    1. 先配置Ubuntu系统语言，设置为中文。可以直接在搜狗官网安装搜狗数据法即可，安装[教程](https://shurufa.sogou.com/linux/guide)
    2. 安装fcitx插件，指令如下
    sudo apt install fcitx-frontend-qt5
    3. 拷贝这个插件到Qt的安装目录，重启Qt Creator
    sudo cp /usr/lib/x86_64-linux-gnu/qt5/plugins/platforminputcontexts/libfcitxplatforminputcontextplugin.so /opt/Qt5*/Tools/QtCreator/lib/Qt/plugins/platforminputcontexts
3. 安装后运行C++示例代码，控制台没有输出，并且会有一个窗口一闪而过，解决办法就是：工具---选项---环境---系统下，x-terminal-emulator -e换成 xterm -e 即可。如下图：  
   ![alt text](.assets_IMG/note/image.png)  

# Qt4.7的工程用Qt5编译报错并解决
1. 编译报错：`error: QtGui/QDialog: No such file or directory #include <QtGui/QDialog>`  
   解决：因为在Qt5中不再使用QtGui模块，而是使用QtWidgets模块。因此，需要
      - 在.pro中加QT+=widgets
      - 将代码中的"QtGui/QDialog"替换为"QtWidgets/QDialog"。
2. 编译报错：`error: ‘UnicodeUTF8’ is not a member of ‘QApplication’`  
   解决：修改setText(QApplication::translate("MainWindow", "&Quitar", 0, QApplication::UnicodeUTF8));为setText(QApplication::translate("MainWindow", "&Quitar", 0));  
   参考：[博客](https://blog.csdn.net/rl529014/article/details/52684506)
3. 编译报错：`error: ‘class QHeaderView’ has no member named ‘setResizeMode’; did you mean ‘ResizeMode’?`
   解决：将 setResizeMode 替换为为 setSectionResizeMode  
   参考：[博客](https://blog.csdn.net/weixin_41521612/article/details/120702977)
4. 编译报错：`error: ‘setCodecForTr’ is not a member of ‘QTextCodec’`
   解决：删掉下面这两行，具体原因可以看下参考博客
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
   参考：[博客](https://blog.csdn.net/qq_34732729/article/details/115513215)

# 如何在Vscode中使用qt
## 第一种方式(使用vscode插件创建)
主要是使用到了一个up主开发的vscode插件`Qt configure`。  
参考[博客](https://blog.csdn.net/cjj_kk/article/details/132579704)(其中这个博客里提到的`配置环境变量`和`配置Kit工具包`都不需要)  
参考[视频](https://www.bilibili.com/video/BV1YL411L7Sg)  
### 步骤
1. Vscode安装插件`Qt configure`
2. ctrl+shift+p打开命令窗口，输入qt，并选择new project选项  
   ![alt text](.assets_IMG/note/image-1.png)  
3. 输入项目名称  
   ![alt text](.assets_IMG/note/image-2.png)  
4. 选择qt套件，cmake，是否带有ui文件(yes)  
   ![alt text](.assets_IMG/note/image-3.png)  
5. 最后生成项目文件  
   ![alt text](.assets_IMG/note/image-4.png)  
   其中launch.json为调试文件。如果其他地方需要调试qt文件，可以将这个文件直接复制过去。  
   跟编译相关的最重要的还是CMakeLists.txt文件。通过该文件，cmake才知道怎么编译。所以`.vscode`中的文件有没有无所谓，都不影响编译。

## 第二种方式(自己编写CMakeLists.txt文件)
这里展示的qtcreator自动生成的最简单板的cmakelist.txt，其他的QT项目可以在这个基础之上来进行改编
```cmake
cmake_minimum_required(VERSION 3.5)

project(TEST LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(TEST
   main.cpp
   mainwindow.cpp
   mainwindow.h
   mainwindow.ui
)

target_link_libraries(TEST PRIVATE Qt5::Widgets)
```
### 注意事项
1. 其中`set(CMAKE_INCLUDE_CURRENT_DIR ON)`表示是否将cmake生成编译文件的目录加入到`include_directories`中，这里的`set(CMAKE_INCLUDE_CURRENT_DIR ON)`也就是相当于在`include_directories`中添加了`${CMAKE_BINARY_DIR}`。
2. `find_package(Qt5 COMPONENTS Widgets REQUIRED)`这里就相当于使用qmake编译时在.pro文件中添加`QT += widgets`是一样的，如果要添加其他的库也是一样的，在COMPONENTS和中REQUIRED写上即可。
3. 其中`set(CMAKE_AUTOUIC ON) set(CMAKE_AUTOMOC ON) set(CMAKE_AUTORCC ON)`这三句其实是普通cmake编译文件与qt的最大区别，cmake也就是通过这三句要分别对qt文件进行转化，简单来说，
   - set(CMAKE_AUTOUIC ON)是控制CMake自动运行uic工具，CMake会自动检测项目中的.ui文件，并生成相应的头文件和源文件，通常以`ui_<WidgetName>.h`命名。
   - set(CMAKE_AUTOMOC ON)是控制CMake自动运行moc工具，CMake会自动检测项目中的头文件和源文件，查找包含Q_OBJECT宏的类，并为其生成支持信号与槽机制的`moc_<ClassName>.cpp`文件。
   - set(CMAKE_AUTORCC ON)是控制CMake自动运行rcc工具，CMake会自动检测项目中的.qrc文件，并使用rcc工具生成相应的源文件（通常以`qrc_<ResourceName>.cpp`命名）。
4. 其中`set(CMAKE_AUTOUIC ON) set(CMAKE_AUTOMOC ON) set(CMAKE_AUTORCC ON)`这三句是让CMake 可以自动管理Qt项目的代码生成任务，如果要手动管理则需要分别使用(注意：其中的FORMS、HEADERS和RESOURCES都可以使用set等来设置)
   - `qt5_wrap_ui(UI_WRAP_FILES ${FORMS})`，其中FORMS为所有ui文件路径的一个集合
   - `qt5_wrap_cpp(CPP_WRAP_FILES ${HEADERS})`，其中HEADERS为所有包含Q_OBJECT宏的头文件的集合
   - `qt5_add_resources(RESOURCES_WRAP_FILES ${RESOURCES})`，其中RESOURCES为所以包含资源文件文件的集合  
5. 补充几个cmake的语法，这些在普通cmake文件中也是适用的，这里写出来是为了强调：
   - 设置动态库的查找目录的link_directories指令一定要在add_executable之前
   - 可以通过`set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)`来设置可执行文件${TARGET}的编译输出路径
   - 如果find_package找不到qt的具体路径，可以通过`set(CMAKE_PREFIX_PATH "/opt/Qt5.12.9/5.12.9/gcc_64")`指令来设置，让find_package指令能找到
### 关于如何在cmake中编译qt的参考博客
1. [Windows下QtCreator使用CMake编译GUI程序(Linux同理)](https://www.cnblogs.com/linuxAndMcu/p/14458427.html)  
   这里讲解了cmake中编译qt的三种方式，其实主要用到的是第一种set(CMAKE_AUTOUIC ON)和第三种qt5_wrap_ui这两个。但是实际测试下来，如果不能具体指定编译文件的具体路径，而是通过类似file(GLOB_RECURSE UI_FILES ${BASE_DIR}/*.ui)这样的方式来广义搜索，使用第一种方式编译是不行的，会报重定义的错误，但是使用qt5_wrap_ui的手动方式就可以。后面可以再留意一下
2. [使用CMake构建Qt项目](https://blog.csdn.net/qq_40181592/article/details/101623231)  
   这里的CMakeList.txt文件比较通用，可以拿来直接借鉴  
   ```cmake
   #cmake版本
   cmake_minimum_required(VERSION 3.5.1)

   #项目名称
   project(Minesweeper)

   #让cmake自动去寻找Qt5
   FIND_PACKAGE(Qt5 COMPONENTS Widgets REQUIRED)

   #采用C++11标准
   set(CMAKE_CXX_STANDARD 11)

   #添加所有的源文件
   SET(Minesweeper_SOURCES 
      dialog.cpp	
      main.cpp 
      mainwindow.cpp 
      minemap.cpp
      myitem.cpp
      myscene.cpp
      setpro.cpp
   )

   #添加所有的头文件
   SET(Minesweeper_HEADERS 
      dialog.h
      mainwindow.h
      minemap.h
      myitem.h
      myscene.h
      setpro.h
   )

   #添加所有的.ui文件
   SET(Minesweeper_FORMS 
      dialog.ui
      mainwindow.ui
      setpro.ui
   )

   #添加资源文件
   SET(Minesweeper_RESOURCES 
      img.qrc
   )
   #调用预编译器moc，需要使用 QT5_WRAP_CPP宏
   QT5_WRAP_CPP(Minesweeper_HEADERS_MOC ${Minesweeper_HEADERS})
   #使用uic处理.ui文件
   QT5_WRAP_UI(Minesweeper_FORMS_HEADERS ${Minesweeper_FORMS})
   #使用rcc处理.qrc文件
   QT5_ADD_RESOURCES(Minesweeper_RESOURCES_RCC ${Minesweeper_RESOURCES})

   #这些生成的中间文件都会在build目录下，这样的话，编译器则不能定位由uic程序产生的诸如_ui_mainwindow.h等文件。所以，我们需要把build目录添加到包含目录中
   INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

   #生成可执行文件
   ADD_EXECUTABLE(Minesweeper 
      ${Minesweeper_SOURCES} 
      ${Minesweeper_HEADERS_MOC} 
      ${Minesweeper_FORMS_HEADERS}
      ${Minesweeper_RESOURCES_RCC} 
   )

   #为target添加需要链接的共享库
   TARGET_LINK_LIBRARIES(Minesweeper ${Qt5Widgets_LIBRARIES})

   ```
3. [CMake教程--QT项目使用CMake](https://blog.csdn.net/m0_46577050/article/details/134348784)  
   这个教程中对cmake中的qt使用做了更详细的说明，并且讲了一些qt6的cmake使用的新特性
4. [一文搞懂如何在CMake中使用Qt](https://blog.csdn.net/Copperxcx/article/details/123116433)  
   这个博客中主要要注意下对cmake变量CMAKE_PREFIX_PATH的设置。如果find_package找不到qt的具体路径，可以通过`set(CMAKE_PREFIX_PATH "/opt/Qt5.12.9/5.12.9/gcc_64")`指令来设置，让find_package指令能找到。以及运行时依赖缺失的处理  
### 关于qt的翻译文件这里单独说明一下
这里针对翻译文件的作用，gpt是这样解释的：  
![alt text](.assets_IMG/note/image-5.png)  
![alt text](.assets_IMG/note/image-6.png)  
所以为了生成翻译文件，qt中有两个工具分别是`lupdate`和`lrelease`。翻译文件的具体使用方式我还没有使用过，这里将知道的先记录一下，之前我在一个工程中的cmakelsit中是这样写的：
```cmake
find_package(Qt5 COMPONENTS LinguistTools REQUIRED)

# 初始化要使用的列表
set(TS_FILES)
set(QM_FILES)

# 将要生成的翻译文件添加到列表中
list(APPEND TS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../translation/QtDemo_zh_CN.ts)

# 设置翻译文件的生成路径，如果不指定就会生成在CMakeFiles的目录里
set_source_files_properties(${TS_FILES}
    PROPERTIES OUTPUT_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/build
)

# 创建翻译的最关键一步
qt5_create_translation(QM_FILES ${TS_FILES} ${PROJECT_SOURCES})

# 添加更新翻译的目标
add_custom_target(lupdate_task DEPENDS ${TS_FILES})
add_custom_target(lrelease_task DEPENDS ${QM_FILES})
```
这样最后只要在执行`cmake ..`的目录中执行`make lupdate_task`和`make lrelease_task`即可。这里可以点开查看一下`cmake ..`生成的`Makefile`文件，在其中搜索lupdate_task和lrelease_task就能看到。  
当源代码发生变化，且需要从中提取新的翻译条目时，你可以运行lupdate_task来确保.ts文件包含最新的字符串。在确保.ts 文件内容正确后，可以运行lrelease_task来生成对应的.qm文件。这些.qm文件是最终用于应用程序中的。
#### 参考博客
1. [Qt Creator + CMake 管理工程翻译文件](https://blog.csdn.net/Tclser/article/details/125364058)  
这个博客对这两个相关的翻译文件讲解的很清楚，其中针对qtcreator如何利用cmake创建这两个翻译文件说的很清楚了。以后用到了可以跟着后面操作一下。

## 在vsode中如何让编写Qt程序有提示
1. Ctrl + Shift + p打开命令窗口
2. 搜索C/Cpp: Edit Configurations，并选择含有json的那一项
3. 然后在includePath这一项添加qt的头文件路径`/opt/Qt5.12.9/5.12.9/gcc_64/include/**`，如下：
   ```json
   {
      "configurations": [
         {
               "name": "Linux",
               "includePath": [
                  "${workspaceFolder}/**",
                  "/opt/Qt5.12.9/5.12.9/gcc_64/include/**"
               ],
               "defines": [],
               "compilerPath": "/usr/bin/gcc",
               "cStandard": "c17",
               "cppStandard": "gnu++14",
               "intelliSenseMode": "linux-gcc-x64"
         }
      ],
      "version": 4
   }
   ```
   注意其中主要就是配置一下includePath这一项，其他的都什么大的作用。有一点要提一下的就是，qt中编译使用的gcc就是ubuntu自带的gcc，qt下载的库中并没有自带gcc。
## qmake和cmake的区别
说到编译顺带记录一下，qmake和cmake是两种工具。qmake是Qt框架专用的一种构建工具，它使用.pro文件来描述项目的结构和依赖关系，然后生成Makefile。cmake是一个更为通用的构建系统，不仅限于Qt项目，也被广泛用于其他C++项目，cmake通过CMakeLists.txt文件来管理项目，这使得它能够处理更复杂的项目配置和跨平台构建。不存是qmake还是cmake，他们最后都是生成Makefile文件。

# Qt教程
[视频教程](https://www.bilibili.com/video/BV1g24y1F7X4)  
[Qt Documentation Archives](https://doc.qt.io/archives/qt-5.12/qtmodules.html)  
