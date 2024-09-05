#ifndef __TWOLIST_H__
#define __TWOLIST_H__
#include <stdio.h>
#include <stdlib.h>
typedef int Datatype; // 节点类型
struct node
{
  Datatype data;     // 数据域
  struct node *next; // 指针域
  struct node *prev; // 指向前一个结点
};

struct nodes
{
  Datatype data;     // 数据域
  struct nodes *next; // 指针域
};
struct list
{
  int nodenum;        // 数据域
  struct node *first; // 指针域
  struct node *last;  // 指针域
};
void printlist(struct list *h);
struct list *creat_list();
struct list *delete_node(struct list *h, Datatype x);
struct list *creat_sort_list();
struct list *add_a_node(struct list *h, Datatype x, Datatype a);
void updata_node(struct list *h, Datatype x, Datatype a);
struct list *destroy_list(struct list *h);
// struct list *is_circle(struct list *h);
#endif