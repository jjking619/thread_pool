#include <stdio.h>
#define stu_lenth 100
struct stu
{
  int num;
  char name[10];
  int grade;
} s[stu_lenth];

int main(int argc, char *argv[])
{
  // 1.以写的方式打开文件
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    perror("fopen failed");
    return -1;
  }
  for (int i = 0; i < stu_lenth; i++)
  {
    int ret = fscanf(fp, "%d%s%d", &s[i].num, s[i].name, &s[i].grade);
  }
  //定义一个变量来保存最大值的
  int max = 0;
  for (int i = 0; i < stu_lenth; i++)
  {
    if (s[i].grade > max)
        {
          max = s[i].grade;
        }
  }
  for (int i = 0; i < stu_lenth; i++)
  {
    if (s[i].grade == max)
    {
      printf("%d %s %d\n", s[i].num, s[i].name, s[i].grade);
    }
  }
  return 0;
}