#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int fd=open(argv[1],O_RDWR);
  if(fd==-1)
  {
    perror("open failed");
    return -1;
  }
  int fd2 = open(argv[2], O_RDWR);
  int ret = 0;
  char buf[1024];
  // char buf1[1024];
  while (ret!=-1)
  {
    ret = read(fd, buf, 100);
    write(fd2, buf, 100);
    printf("%d\n", ret);
  }
  close(fd);
  close(fd2);
  return 0;
}