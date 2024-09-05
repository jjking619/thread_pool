#include <stdio.h>

int main(int argc,char *argv[])
{
    //1.打开文件  
    FILE *fp = fopen(argv[1],"r+");//以读写的方式打开这个文件 
    if(fp == NULL)
    {
        perror("fopen failed");
        return -1;
    }

    fputc('a',stdout);
    //2.从文件中读取一个字符 
    char c = fgetc(fp);
    printf("c:%c %d\n",c,c);

    char c2 = fgetc(stdin);//从键盘上获取一个字符
    printf("c2:%c %d\n",c2,c2);

    //3.关闭一个文件流
    fclose(fp);

    return 0;
}