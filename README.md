# SimpleSerialConnectorDemo
[java-simple-serial-connector](https://code.google.com/archive/p/java-simple-serial-connector/)这个开源库最后一次维护是2014年3月12日，年代比较久远了，直接使用jar包会报错，于是把源码下载下来，自己编译。
## 注意事项
- 新建一个包，把jssc的java代码粘贴进去，新建src\main\jni文件夹，把cpp的源码放入
- 在jni文件夹中新建Android.mk文件，内容如下
```
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := jssc
LOCAL_SRC_FILES := jssc.cpp
include $(BUILD_SHARED_LIBRARY)
```
- 同一目录新建Application.mk文件，内容如下
```
APP_MODULES := jssc
APP_ABI := all
APP_STL := stlport_static
```
- 用`javah -jni com.example.gourdboy.serialportdemo.jssc.SerialNativeInterface `生成cpp的头文件
- 修改jssc.cpp的代码，把刚才生成的头文件include进去，大致如下
```c
#include "termios.h"
#ifdef __linux__
    #include "serial.h"
#endif
#include "com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface.h"
```
- 以上都是需要修改的地方，主要是`java.lang.UnsatisfiedLinkError: dlopen failed: cannot locate symbol tcgetattr referenced by libserial_port.so...`错误造成的，这个错误是因为现版ndk和之前ndk的termios.h文件的不同造成的
- 最后记得把jssc.cpp文件中所有的方法，都改成jni生成头文件中声明的方法
