#include <stdio.h>

int main(int argc,char *argv[])
{
  //1.以写的方式打开文件
  FILE *fp = fopen(argv[1], "w+");
  if (fp==NULL)
  {
    perror("fopen failed");
    return -1;
  }
  int a[10] = {0};
  //写入
  int ret=fwrite(a, 4, 10, fp);
  if(ret ==-1)
  {
    perror("fwrite failed!");
    return -1;
  }
  printf("ret:%d\n", ret);
  fclose(fp);
  //重新打开文件
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    perror("fopen failed");
    return -1;
  }
  //读取
  int b[10];
  ret=fread(b, 4, 10, fp);
  if (ret == -1)
  {
    perror("fwrite failed!");
    return -1;
  }
  printf("ret:%d\n", ret);
  for (int i = 0; i <10; i++)
  {
    printf("%d",b[i]);
  }
  return 0;
}