#include "cp_dir.h"
int count = 0; //记录任务数
void cp(void *arg) {
    struct cp_file *p = (struct cp_file *)arg;
    int fd1 = open(p->srcname, O_RDONLY);
    if (fd1 == -1) {
        perror("open source file error");
        return ;
    }

    int fd2 = open(p->destname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1) {
        perror("open destination file error");
        close(fd1);
        return ;
    } 

    char buf[1024];
    ssize_t ret, ret_write;
    while (1) {
        ret = read(fd1, buf, 1024);
        if (ret == 0) {
            break;
        } else if (ret > 0) {
            ret_write = write(fd2, buf, (size_t)ret);
            if (ret_write == -1) {
                perror("write error");
                break;
            }
        } else {
            perror("read error");
            break;
        }
    }

    close(fd1);
    close(fd2);
    return ;
}

void cp_dir(char *src, char *dest, thread_pool *pool)
{

    char new_dir[MAX] = {0};
    //将src的路径中的文件名提取出来
    //并将刚才获取的文件名与目标路径组成新的目录名(要创建新目录)
    sprintf(new_dir, "%s/%s", dest, basename(src));
    if (mkdir(new_dir, 0777) == -1)
    {
      perror("mkdir error");
      return;
    }
    dest = new_dir; //更新目标目录路径
    //读取src这个目录
    DIR *dir = opendir(src);
    if (dir == NULL) {
        perror("opendir error");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char src_path[MAX] = {0};
        char dest_path[MAX] = {0};
        sprintf(src_path, "%s/%s", src, entry->d_name);
        sprintf(dest_path, "%s/%s", dest, entry->d_name);
        struct stat st;
        if (lstat(src_path, &st) == -1) {
            perror("lstat error");
            continue;
        }

        if (S_ISDIR(st.st_mode))
         {
             cp_dir(src_path, new_dir, pool);
         } 
        else if (S_ISREG(st.st_mode) || S_ISLNK(st.st_mode)) {
            pthread_t tid;
            // struct cp_file cf = {0};
            // strcpy(cf.srcname, src_path);
            // strcpy(cf.destname, dest_path);
            struct cp_file *p =malloc(sizeof(*p));
            strcpy(p->srcname, src_path);
            // printf("p->srcname:%s\n", p->srcname);
            strcpy(p->destname, dest_path);
            // printf("p->destname:%s\n", p->destname);
            // 创建一个线程 
            printf("任务%d:\n", ++count);
            add_task(pool,cp,(void *)p);
             if (pool->cur_waiting_task >= 4 && pool->thread_nums < MAX_thread_num)
            {
                add_threads(pool, 2);
                // printf("add后线程数%d\n", pool->thread_nums);
            }
            if (pool->thread_nums > MIN_thread_num && pool->cur_waiting_task <= 3)
            {
                    remove_threads(pool);
            }
        }
    }

    closedir(dir);
}
