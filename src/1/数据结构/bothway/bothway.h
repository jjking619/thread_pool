#ifndef __BOTHWAY_H__
#define __BOTHWAY_H__
#include <stdio.h>
#include <stdlib.h>
typedef int Datatype; // 节点类型
struct nodes
{
  Datatype data;     // 数据域
  struct nodes *next; // 指针域
  struct nodes *prev; //指向前一个结点
};
struct list
{
  int nodenum;        // 数据域
  struct nodes * first; // 指针域
  struct nodes *last;  // 指针域
};
void printlist(struct list *h);
struct list *creat_list();
struct list *delete_node(struct list *h, Datatype x);
struct list *creat_sort_list();
struct list *add_a_node(struct list *h, Datatype x, Datatype a);
void updata_node(struct list *h, Datatype x, Datatype a);
struct list *destroy_list(struct list *h);
#endif