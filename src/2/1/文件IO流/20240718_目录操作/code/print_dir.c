/*
练习1：把一个大目录下的所有文件的文件名打印出来
*/
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
int main(int argc,char *argv[])
{
    //1.打开一个目录 
    DIR *dirp = opendir(argv[1]);
    if(dirp == NULL)
    {
        perror("opendir error");
        return -1;
    }
    //2.读取一个目录
    struct dirent * dir;
    while(dir = readdir(dirp))
    {
        char filename[512]={0};
        printf("%s ",dir->d_name);//文件的名字
        sprintf(filename,"%s/%s",argv[1],dir->d_name);//合法路径文件名 可以用stat获取它的属性
        printf("filename:%s\n",filename);
    }
    //3.关闭目录
    closedir(dirp);

    return 0;
}