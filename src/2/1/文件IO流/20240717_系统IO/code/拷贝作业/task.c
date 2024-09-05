#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  // 1.打开两个文件
  int read_fd = open(argv[1], O_RDWR);
  if (-1 == read_fd)
  {
    perror("open read failed");
    return -1;
  }
  int write_fd = open(argv[2], O_RDWR);
  if(-1==write_fd)
  {
    perror("open write failed");
    return -1;
  }
  // 2.循环读取文件的数据
  int i = 0;
  while (1)
  {
    char buf[1024] = "";
    int num = read(read_fd, buf, 100);
    if(num==0)
    {
       break;
    }
    write(write_fd, buf, num);
    printf("第%d次拷贝,拷贝了%d个字节\n", ++i, num);
  }
  printf("copy OK!!!\n");
  //3.关闭文件
  close(read_fd);
  close(write_fd);

  return 0;
}