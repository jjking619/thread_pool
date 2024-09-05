#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/*
     求一个目录下所有普通文件的大小，目录下还有目录(递归)
     get_dir_size：求这个目录的大小
*/
int get_dir_size(char *dirname)
{
  // 打开目录
  DIR *dirp = opendir(dirname);
  if (dirp == NULL)
  {
    perror("open dir failed");
    return -1;
  }
  // 读取目录
  struct dirent *dir;
  struct stat st;
  int sum = 0;
  while (dir = readdir(dirp))
  {
    char filename[512] = {0};
    sprintf(filename, "%s/%s", dirname, dir->d_name);
    if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
    {
      continue;
    }
    int ret=stat(filename, &st);
    if(ret==-1)
    {
      perror("lstat failed");
      return -1;
    }
    if (S_ISDIR(st.st_mode))
    {
      sum += get_dir_size(filename);
    }
    // 如果目录项是一个普通文件，sum += st_size
    if (S_ISREG(st.st_mode))
    {
      sum += st.st_size;
    }
  }
    // 关闭目录
    closedir(dirp);
    return sum;
}
int main(int argc, char *argv[])
{
  int ret = get_dir_size(argv[1]);
  printf("%d", ret);
  return 0;
}
    