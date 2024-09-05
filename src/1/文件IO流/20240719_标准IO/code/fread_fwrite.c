/*
练习1： 将一个int类型含有10个元素的数组 写入到一个空的文本中，观察文本中的现象 再从文件中将10个元素读取出来，并打印 
*/
#include <stdio.h>

int main(int argc,char *argv[])
{
    //1.以写的方式打开文件 
    FILE *fp = fopen(argv[1],"w+");
    if(fp == NULL)
    {
        perror("fopen failed");
        return -1;
    }
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int ret = fwrite(a,4,10,fp);
    if(ret == -1)
    {
        perror("fwrite failed");
        return -1;
    }
    printf("ret:%d\n",ret);
    fclose(fp);

    //重新打开文件 
    fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        perror("fopen failed");
        return -1;
    }
    int b[10]={0};
    //将数组从文本中读取出来
    ret = fread(b,4,10,fp);
    if(ret == -1)
    {
        perror("fread failed");
        return -1;
    }
    printf("ret:%d\n",ret);
    int i;
    for(i=0;i<10;i++)
    {
        printf("%d ",b[i]);
    }
    putchar('\n');
    fclose(fp);

    return 0;
}