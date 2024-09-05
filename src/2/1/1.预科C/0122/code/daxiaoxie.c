#include <stdio.h>


int main()
{
    //S1:输入一个字符 
    char ch;
    printf("请输入一个字符:\n");
    scanf("%c",&ch);

    //S2:判断它是不是一个英文字母 ,是大写还是小写
    if(ch >= 'A' && ch <= 'Z')//大写字母
    {
        ch = ch + 32;//改变它的值找到对应ASCII码
        printf("转变后的字符为:%c\n",ch);
    }
    else if(ch >= 'a' && ch <= 'z')//小写字母
    {
        ch = ch - 32;
        printf("转变后的字符为:%c\n",ch);
    }
    else
    {
        printf("您输入的字符不是一个字母\n");
    }

    return 0;
} 