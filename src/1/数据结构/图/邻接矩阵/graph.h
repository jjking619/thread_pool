#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <stdlib.h>
#include <stdio.h>

typedef char Vtype;//顶点的类型
typedef int Adjtype;//权值的类型 

#define MAXN 120 
#define MAXNUM 65535  //最大值表示两个顶点之间没有路径  无穷大 

typedef struct Graph  //图的数据类型
{
    Vtype V[MAXN];//一维数组存顶点
    Adjtype Adj[MAXN][MAXN];//用二维数组来保存边上权的集合
    int vexnum;//图中顶点的个数
    int arcnum;//图中边的条数 
}Graph;

int find_index(Vtype *v,int n,Vtype x);
Graph *Create_graph();
void print_graph(Graph *g);
void DFS(Graph *g,int v_index);
void DFS_pro(Graph *g,int v_index);
void BFS(Graph *g,int vindex);
void Dijkstra(Graph *g,int v);
void print_dist(Graph *g,int v);
void print_path(Graph *g,int v);
#endif 
