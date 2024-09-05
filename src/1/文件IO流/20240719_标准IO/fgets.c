#include <stdio.h>

int main()
{
  char s1[5];
  char s2[5];
  // gets(s1);
  fgets(s2,5,stdin);
  printf("%s\n", s2);
  if (s2[3] == '\n')
  {
    printf("n");
  }
  if(s2[4]=='\0')
  {
    printf("0");
  }
  // printf("%s\n", s2);
}