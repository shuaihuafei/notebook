# Linux如何卸载QtCreator
1. 首先通过指令`sudo find / -name qtcreator 2>/dev/null`找到qtcreator的安装目录
2. 进入qtcreator的安装目录，执行卸载指令`sudo ./QtCreatorUninstaller`
## 参考
[ubuntu18.04 LTS卸载qtcreator-10.0.2](https://blog.csdn.net/lyc_daniel/article/details/133858141)

# Linux安装Qt5.12.9后的注意事项
具体安装过程可以参考`【正点原子】I.MX6U嵌入式Qt开发指南V1.1.pdf`的第52页
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




