#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
  int fd = open(argv[1], O_RDWR);
  if (-1 == fd)
  {
    printf("open %s error!!\n", argv[1]);
    printf("errno:%d\n", errno);
    return -1;
  }
  printf("OK!!!\n");
  printf("fd:%d\n", fd);

  return 0;
}