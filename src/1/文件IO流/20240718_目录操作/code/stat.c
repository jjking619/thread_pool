#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
struct stat st;
int main(int argc, char *argv[]) //./main 1.txt 10
{
  // atoi函数可以把数字字符串转换成数字 "123"-->123
  int ret=stat(argv[1], &st);
  if(ret==-1)
  {
    perror("stat falied!!");
  }
  if (S_ISREG(st.st_mode))
  {
    printf("%ld", st.st_size);
  }


  return 1;
}