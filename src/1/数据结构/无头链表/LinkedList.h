#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include<stdio.h>
#include <stdlib.h>
typedef int Datatype; //节点类型
struct  nodes
{
  Datatype data; //数据域
  struct nodes *next; //指针域
};

void printflist(struct nodes *h);
struct nodes *creat_sort_list(void);
struct nodes *add_node(struct nodes *h, Datatype x, Datatype a);
struct nodes *delete_node(struct nodes *h, Datatype x);
struct nodes *modify_node(struct nodes *h, Datatype x, Datatype a);
struct nodes *creat_list();
#endif 