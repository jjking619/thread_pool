#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <libgen.h>
// #define MAX_task_num 1000  // 最大任务数
#define Del_Thread 4
#define Check_Time 10      // 检查时间
#define MIN_thread_num 10  // 最小线程数量
#define MAX_thread_num 100 // 最大线程数
#define MAX_task_num 100   // 最大任务数
typedef struct pthread_pool
{
  // 线程池的实现是按照项目的不同，成员也会有所不同，但是应该要有如下的成员
  //"任务队列"是一个共享资源，需要互斥访问，需要线程互斥锁
  pthread_mutex_t mutex;  //给线程池加锁
  // 当任务队列中没有任务的时候，线程池内的线程应该休眠，需要条件变量
  pthread_cond_t cond;   //  任务队列是不是空的唤醒线程的条件变量
  // pthread_cond_t cond2;  //  任务队列是不是满了  
  //"任务队列"(链表),定义一个指针，指向第一个任务
  // 所有的线程都必须从这个任务链表中取任务
  struct task *task_list;
  // 指向所有线程的tid的数组
  pthread_t *tids;
  // 指向管理者的线程
  pthread_t manageid;
  // 线程池目前正在服役的线程数
  unsigned int thread_nums;
  // 线程池目前正在服役的做线程数
  //要删除的线程
  pthread_t exitNum;
  // 线程池任务队列目前任务的数量
  unsigned int cur_waiting_task;
  // 表示线程池是否要关闭  1表示打开,0表示关闭
  int shutdown;   
} thread_pool;
// 任务结点的类型
struct task
{
  // 每一个任务结点都保存了独一无二的任务，比如应用在文件夹拷贝中
  // 需要执行cpfile这个函数去实现一个普通文件的拷贝，这个函数还需要指定的参数
  // 那么这个任务怎么保存？
  // 需要一个函数指针去指向cpfile函数，同时还需要参数指针去指向参数  比如 void cpfile(void *arg)
  void (*do_task)(void *arg);
  void *task_arg;
  struct task *next;
};
int init_pool(thread_pool *pool, int thread_num);
int add_task(thread_pool *pool, void (*fun_task)(void *fun_arg), void *task_arg);
int destroy_pool(thread_pool *pool);
void *routine(void *arg);
void add_threads(thread_pool *pool, unsigned int add_thread_nums);
void *manage_thread(void *arg);
void remove_threads(thread_pool *pool);
void threadExit(thread_pool *pool);
#endif