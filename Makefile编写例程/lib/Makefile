#变量
#配置编译器
CC = gcc
#宏定义(-D开头)
DEFINES =
#头文件包含(-I开头)
INCLUDE = -I./
#链接库的路径(-L开头)
LDFLAGS =
#需要调用的链接库(-l开头，去掉lib和.so)
LIBS =
#编译器参数
CFLAGS = -c -Wall -g $(DEFINES) $(INCLUDE) $(LDFLAGS) $(LIBS) -std=c99 -O1

#[目标]:[依赖]
#	[命令]
#默认从前面的目标开始
libsub.so:sub.o
	$(CC) -shared $^ -fPIC -o $@

#这里%表示任意通配
sub.o:sub.c
	$(CC) $^ -fPIC $(CFLAGS) -o $@

#声明伪目标，即clean不是一个文件
.PHONY:clean
clean:
	$(RM) *.so *.o -r