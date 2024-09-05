#ifndef __LINKEDLISTWITHHEAD_H__
#define __LINKEDLISTWITHHEAD_H__
#include <stdio.h>
#include <stdlib.h>
typedef int Datatype; // 节点类型
struct node
{
  Datatype data;     // 数据域
  struct node *next; // 指针域
};
struct list
{
  int nodenum;     // 数据域
  struct node *first; // 指针域
  struct node *last; // 指针域
};
void printlist(struct list *h);
struct list *creat_list();
struct list *creat_sort_list();
struct list *add_a_node(struct list *h, Datatype x, Datatype a);
struct list *delete_node(struct list *h, Datatype x);
struct list *updata_node(struct list *h, Datatype x, Datatype a);
struct list *destroy_list(struct list *h);
struct list *is_childlist(struct list *a, struct list *b);
struct list *insert_list(struct list *h);
struct list *request_merge(struct list *a, struct list *b);
// 包含在头文件
struct list *list_reverse(struct list *a);
struct list *merge_list(struct list *a, struct list *b);
struct list *sort_list(struct list *a);
//自定义函数
// struct list *sortlist(struct list *a);

#endif