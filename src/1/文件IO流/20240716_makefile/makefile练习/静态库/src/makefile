target:=tree
libpath := ../lib
srcpath := .
headpath:=../inc
libname:=tree
cc :=gcc

csrcs :=$(wildcard $(srcpath)/*.c) 
objs :=$(patsubst %.c,%.o,$(csrcs))

$(target):$(objs)
		$(cc) $+ -o $@

%.o :%.c
		$(cc) -c $< -o $@ -I$(headpath)

		
clean : 
		rm -rf $(objs) $(target)