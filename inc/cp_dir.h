#ifndef  __CP_DIR_H__
#define  __CP_DIR_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>
#include <dirent.h>
#include <libgen.h>
#include "thread_pool.h"
#define MAX 1024

struct cp_file
{
  //源文件
  char srcname[MAX];
  //目标文件
  char destname[MAX];
};
extern int count;
void cp_dir(char *src, char *dest, thread_pool *pool);
void cp(void *arg);
#endif