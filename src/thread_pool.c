#include "thread_pool.h"
int count; //任务数
// 线程池代码的具体实现：
/*
    init_pool:线程池初始化函数，在线程池中创建thread_num个线程
        @pool：要初始化的线程池
        @thread_num：线程池中线程的个数
    返回值：
        成功返回0   失败返回-1
*/
int init_pool(thread_pool *pool, int thread_num)
{
  pthread_mutex_init(&pool->mutex, NULL);
  pthread_cond_init(&pool->cond, NULL);
  // 初始化线程池结构体中每个成员的初值
  pool->task_list = NULL;
  // 线程池目前正在服役的线程数
  pool->thread_nums = thread_num;
  // 线程池任务队列目前任务的数量
  pool->cur_waiting_task = 0;
  // 表示线程池是否要关闭  1表示打开,0表示关闭
  pool->shutdown = 0;
  // 指向所有线程的tid的数组
  pool->tids = malloc(sizeof(pthread_t) * MAX_thread_num); // 给进程分配空间
  memset(pool->tids, 0, sizeof(pthread_t) * MAX_thread_num);
  int i;
  for (i = 0; i < pool->thread_nums; i++)
  {
    if (pthread_create(&((pool->tids)[i]), NULL, routine, (void *)pool) != 0)
    // 返回值为0表示创建成功，返回不为0表示创建失败
    {
      perror("线程创建失败"); // 根据传入的线程数，逐一创建线程，存入tid[]
      return -1;
    }
  }
  // pthread_create(&pool->manageid, NULL, manage_thread, (void *)pool);
  printf("初始化线程数为:%d\n", pool->thread_nums);
  return 0;
}
/*
    routine:任务调度函数(线程函数)，所有线程一开始就应该执行这个函数。此函数应该会不断的从线程池中的任务队列中取任务
            然后根据取到的任务结点中的函数指针去执行相应的函数，如果没有任务可以取，休眠
        如何取任务:arg表示的线程池的指针
*/
void *routine(void *arg)
{ 
  thread_pool *p=(thread_pool *)arg;
  while (1)
  { 
    pthread_mutex_lock(&p->mutex);
    // 检查是否有关闭信号且没有任务
    while(p->cur_waiting_task==0 && (p->shutdown == 0 ||p->exitNum!=pthread_self()) && p->shutdown!=1 )
    {
      // 陷入休眠
      pthread_cond_wait(&p->cond, &p->mutex);
    }
      // 线程池关闭
    if (p->shutdown==1)
    {
        pthread_mutex_unlock(&p->mutex);
        pthread_exit(NULL);
    }
    if(p->shutdown==2&&pthread_self()==p->exitNum)
    {
      pthread_mutex_unlock(&p->mutex);
      pthread_exit(NULL);
    }
    else{
       struct task *q = p->task_list;  //任务列表的头结点
        p->task_list = q->next;
        p->cur_waiting_task--;
        printf("线程池任务队列现在任务的数量:%d\n", p->cur_waiting_task);
        printf("当前线程数%d\n", p->thread_nums);
        printf("线程%ld-开始执行任务%d\n", pthread_self(), count);
        pthread_mutex_unlock(&p->mutex);
        (q->do_task)(q->task_arg);
        q->next = NULL;
        printf("线程%ld-结束执行任务%d\n", pthread_self(), count);
        free(q);
    }
  }
  return NULL;
}

/*
    add_task:给任务队列添加任务，把fun_task和fun_arg指向的参数封装成一个任务结点，添加进任务队列
        @pool：要添加任务的线程池
        @fun_task：你要添加的任务函数 -->cpfile
        @fun_arg:你要执行的那个函数需要的参数
    返回值：
        成功返回0  失败返回-1
*/
int add_task(thread_pool *pool, void (*fun_task)(void *fun_arg), void *task_arg)
{
  // 首先需要把第二个参数和第三个参数封装成struct task *的类型  
  struct task *pnew = malloc(sizeof(*pnew));
  // 初始化
  pnew->do_task = fun_task;
  pnew->task_arg = task_arg;
  pnew->next = NULL;
  // P操作
  pthread_mutex_lock(&pool->mutex); 
  struct task *tmp = pool->task_list;
  if (pool->task_list == NULL)
  {
    pool->task_list = pnew;
  }
  else{
      while (tmp->next != NULL) // 从任务结点取到不为空，就是取到任务
      {
        tmp = tmp->next; // 把这个任务取出来，拿到tmp上
    }
       // 尾插法把任务结点插入
    tmp->next=pnew;
  }
  pool->cur_waiting_task++;
  printf(" 线程池任务队列添加任务后当前任务的数量:%d\n", pool->cur_waiting_task);
  // V操作
  pthread_mutex_unlock(&pool->mutex);
  // 唤醒休眠的线程
  pthread_cond_signal(&pool->cond);
   return 1;
}


// 往线程池中添加线程
void add_threads(thread_pool *pool, unsigned int add_thread_nums)
{
    pthread_mutex_lock(&pool->mutex);
     // 计算线程总数
    unsigned int  total_threads = pool->thread_nums + add_thread_nums;
    int i, actual_thread = 0;
    for (i = pool->thread_nums; i < total_threads; i++)
    {
        pthread_create(&((pool->tids)[i]), NULL, routine, (void *)pool);
        actual_thread++;
     }
    // printf("实际添加线程数为:%d\n", actual_thread);
    pool->thread_nums += actual_thread;
    pthread_mutex_unlock(&pool->mutex);
    printf("add后线程数%d\n", pool->thread_nums);
}

  // 删除指定线程池中的线程
void remove_threads(thread_pool *pool)
  {
    if (pool->thread_nums <= MIN_thread_num)
    {
      return; // 不能删除低于最小线程数量的线程
    }
    // 选择一个线程进行删除，这里简单地选择最后一个线程
    pthread_mutex_lock(&pool->mutex);
    int index_to_remove = pool->thread_nums - 1;
    pool->exitNum = pool->tids[index_to_remove];
    pool->shutdown = 2;
    pthread_mutex_unlock(&pool->mutex);
    pthread_cond_broadcast(&pool->cond);
    // 等待线程完成其任务
    pthread_join(pool->exitNum, NULL);
    pool->thread_nums--; // 更新线程数量
    printf("Thread %ld has finished its task and exited.\n", pool->exitNum);
  }

 /*
         destroy_pool:摧毁整个线程池
*/
int destroy_pool(thread_pool *pool)
 {
   // 第一个确定任务队列中没有任务了
   sleep(1);
   if (pool->cur_waiting_task == 0)
   {
     pool->shutdown = 1 ;
      pthread_cond_broadcast(&pool->cond);
      int count = pool->thread_nums;
      for (int i = 0; i < count; i++)
      {
        pthread_join(pool->tids[i], NULL);
      }
    printf("线程池已销毁！\n");
  }
  free(pool);
  free(pool->tids);
}
