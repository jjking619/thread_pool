#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc,char *argv[])//./main 1.txt 10
{
    //atoi函数可以把数字字符串转换成数字 "123"-->123
    int ret = truncate(argv[1],atoi(argv[2]));
    if(ret == -1)
    {
        perror("truncate failed");
        return -1;
    }
    rmdir("./1");

}