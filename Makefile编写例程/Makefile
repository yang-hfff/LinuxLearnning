#变量
#配置编译器
CC = gcc
#宏定义(-D开头)
DEFINES = -D__XXX__
#头文件包含(-I开头)
INCLUDE = -I./inc -I./lib
#链接库的路径(-L开头)
LDFLAGS = -L./lib
#需要调用的链接库(-l开头，去掉lib和.so)
LIBS = -lsub
#编译器参数
CFLAGS = -c -Wall -g $(DEFINES) $(INCLUDE) $(LDFLAGS) $(LIBS) -std=c99 -O1

#[目标]:[依赖]
#	[命令]
#默认从前面的目标开始
./build/out:./build/add.o ./build/main.o 
	cd ./lib && $(MAKE)
	cp ./lib/libsub.so ./build/
	$(CC) $^ ./lib/libsub.so -o $@

#这里%表示任意通配
./build/%.o:./src/%.c
	$(CC) $^ $(CFLAGS) -o $@

#声明伪目标，即clean不是一个文件
.PHONY:clean
clean:
	$(RM) ./build/*.o ./build/*.exe ./build/*.so -r
	cd ./lib && $(MAKE) clean