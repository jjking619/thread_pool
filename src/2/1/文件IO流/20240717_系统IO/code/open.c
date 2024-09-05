#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
    int fd = open(argv[1],O_RDWR);
    if(-1 == fd)
    {
        perror("open failed");
        return -1;
    }
    printf("%d", fd);
    close(fd);
}