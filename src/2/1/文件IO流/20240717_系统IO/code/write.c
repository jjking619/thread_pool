#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[])
{
    //1.打开一个文件
    int fd = open(argv[1],O_RDWR);
    if(-1 == fd)
    {
        perror("open failed");
        return -1;
    }
    //2.写入数据
    char buf[1024]="123456";
    int num = write(fd,buf,strlen(buf));
    if(-1 == num)
    {
        perror("write error");
        return -1;
    }
    //3.打印数据 
    printf("num:%d\n",num);
    close(fd);
    return 0;
}