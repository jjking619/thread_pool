#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    //1.打开一个文件
    int fd = open(argv[1],O_RDWR);
    if(-1 == fd)
    {
        perror("open failed");
        return -1;
    }
    //2.读取文件的数据 
    char read_buf[1024]={0};
    int num = read(fd,read_buf,1023);
    if(-1 == num)
    {
        perror("read error");
        return -1;
    }
    //3.打印数据 
    printf("read_buf:%s\n",read_buf);
    printf("num:%d\n",num);

    //4.关闭文件
    close(fd);

    return 0;
}