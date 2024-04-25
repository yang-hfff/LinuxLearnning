# Linux开机自启动

## 向rc.local文件添加启动代码

修改rc.local文件，在终端输入并回车：

> xxx@Linux:~ $ sudo vi /etc/rc.local

在打开的文本中找到exit 0，在此之前添加的代码在启动时都会被执行，在exit 0 之前添加一行代码：

```
#!/bin/sh -e
#
# rc.local
#
# This script is executed at the end of each multiuser runlevel.
# Make sure that the script will "exit 0" on success or any other
# value on error.
#
# In order to enable or disable this script just change the execution
# bits.
#
# By default this script does nothing.

# 在这里添加待开机启动的命令

exit 0
```

别忘了给rc.local 添加可执行的权限
> sudo chmod +x /etc/rc.local

ctrl+o保存，ctrl+x退出，然后在终端输入：sudo reboot ,重启系统测试。

**注意：系统启动时在执行这段代码时是使用root用户权限的，如果不指定用户，可能会因为权限问题导致脚本执行失败。**

## 通过桌面启动

此方法是在加载了桌面后再启动我们自定义的程序，因此需要安装带有桌面的版本，如果不是请跳过。

在/home/pi/.config/目录下新建一个名为 autostart 的文件夹：

> pi@raspberry:~ $ mkdir .config/autostart

在 autostart 目录下新建testboot.desktop （经测试名字任意，但后缀必须是.desktop）：

> pi@raspberry:~ $ nano .config/autostart/testboot.desktop

文件内容如下：

> [Desktop Entry]
>
> Type=Application
>
> Name=testboot
>
> NoDisplay=true
>
> Exec=/home/pi/testboot.sh

sudo reboot 重启测试。

**注意：这个方法除了依赖桌面之外，如果开启了多个桌面则会导致自定义的程序多次启动。比如系统启动桌面会调用一次testboot.sh脚本，如果再用远程桌面登录到树莓派，脚本会再执行一次。**