#include "cp_dir.h"
#include "thread_pool.h"

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <src_dir> <dest_dir>\n", argv[0]);
    return 1;
  }
  // 定义一个线程池
  thread_pool *pool = malloc(sizeof(*pool));
  // 初始化一个线程池
  init_pool(pool, 10);
  // 利用线程池去拷贝文件夹
  cp_dir(argv[1], argv[2], pool);
  // 摧毁一个线程池
  destroy_pool(pool);
}