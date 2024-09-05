TARGET :=tree
CC :=gcc
HEADPATH :=../inc
SRCPATH :=.        #表示当前目录，即源代码文件所在的目录
LIBPATH :=../lib
LIBNAME :=xxx

CSRCS :=$(wildcard $(SRCPATH)/*.c)   
#：使用wildcard函数查找srcpath（即当前目录）下所有.c文件，并将它们赋值给变量csrcs。
OBJS :=$(patsubst %.c,%.o,$(CSRCS))
#使用patsubst函数将csrcs中所有的.c文件扩展名替换为.o，生成对象文件列表，赋值给变量objs。

$(TARGET) : $(OBJS) 
	$(CC) $+ -o $@  
#这是一个目标规则，目标为$(target)（即tree），依赖为$(objs)（即所有.c文件对应的.o文件）。
#当执行make命令时，如果没有tree文件或tree文件比任何.o文件旧，make会尝试构建tree。
#命令：$(cc) $+ -o $@。这里$+代表所有的依赖（即.o文件），$@代表目标（即tree）。
#这条命令使用GCC编译器将所有.o文件链接成可执行文件tree。

%.o : %.c  
	$(CC) -c $< -o $@ -I$(HEADPATH) 
#命令：$(cc) -c $< -o $@ -I$(headpath)。这里$<代表规则中的第一个依赖（即.c文件），$@代表目标（即.o文件）。
#-c选项告诉GCC只编译和汇编，但不链接。
#-I$(headpath)选项告诉GCC在编译时包含headpath（即../inc）目录下的头文件。

clean :
	rm -rf $(OBJS) $(TARGET)
#这条命令删除所有.o文件和tree可执行文件

 