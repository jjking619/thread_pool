#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
    char *p = get_current_dir_name();
    if(p == NULL)
    {
        perror("getwd error");
        return -1;
    }
    printf("%s\n",p);
    free(p);

    return 0;
}