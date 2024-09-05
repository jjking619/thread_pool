#include<stdio.h>
#include <string.h>

int mystrlen(char* p) 

    while ((*p) != '\0') 
    {
        len++;
        p++;
    }
    return len;
}


int main() 
{
    char s1[8];
    char s2[8] = {"ABCDEFG"};
        //有些编译器,在分配内存的时候,一般是连续的
          //  s1和s2有可能是连续的地址

    strcpy(s1,"123456789");
    printf("%s\n",s1);  //123456789
    printf("%s\n",s2);  //9
    return 0;
}