#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <stdio.h>
#include <stdlib.h>
typedef int Datatype;
struct  nodes 
{
  Datatype data; //数据域
  struct nodes *next; //指针域
};
struct nodes *Creat_List(void);
void Printf_List(struct nodes *h);
#endif 