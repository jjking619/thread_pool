#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
struct stat st;
int main(int argc, char *argv[])
{
  DIR *dir = opendir(argv[1]);
  if (dir == NULL)
  {
    perror("open dir failed");
    return -1;
  }
   struct dirent *p;
  while (p=readdir(dir))
  {
    printf("%s", p->d_name);
  }
  closedir(dir);
  return 0;
}