#include "graph.h"
#include "CircleQueue.h"

/*
    find_index:返回顶点x在v数组中的下标
*/
int find_index(Vtype *v,int n,Vtype x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(v[i] == x)
        {
            return i;
        }
    }
    return -1;//-1表示没有找到该元素
}
/*
    根据用户的输入创建一个图
*/
Graph *Create_graph()
{
    int i,j;
    /*step1:先创建一个图*/
    Graph *g = malloc(sizeof(*g));
    g->vexnum = 0;
    g->arcnum = 0;
    //把二维数组里面的值都给无穷大
    for(i=0;i<MAXN;i++)
    {
        for(j=0;j<MAXN;j++)
        {
            g->Adj[i][j] = MAXNUM;
        }
    }
    /*step2:先输入图中的顶点并存入顶点数组*/
    printf("Please input the vertex value:\n");
    char vex[MAXN];
    gets(vex);

    i=0;
    while(vex[i])//避免把'\0'这个字符输入到顶点数组中
    {
        g->V[i] = vex[i];
        g->vexnum++;
        i++;
    }
    /*step3:根据输入初始化邻接矩阵*/
    printf("Please input the R value:\n");
    while(1)
    {
        Vtype s,d;
        int w;
        scanf("%c%c%d",&s,&d,&w);
        getchar();//吸收换行符
        if(s == '#'|| d == '#')
        {
            break;
        }
        int si = find_index(g->V,g->vexnum,s);
        int di = find_index(g->V,g->vexnum,d);
        if(si != -1 && di != -1)
        {
            g->Adj[si][di] = w;
            g->arcnum++;
        }

    }

    return g;
}
/*
    把图的矩阵形式打印出来
*/
void print_graph(Graph *g)
{
    int i,j;
    printf("顶点数组:\n\t");
    for(i=0;i<g->vexnum;i++)
    {
        printf("%c\t",g->V[i]);
    }
    printf("\n");

    for(i=0;i<g->vexnum;i++)
    {
        printf("%c\t",g->V[i]);
        for(j=0;j<g->vexnum;j++)
        {
            if(g->Adj[i][j] == MAXNUM)
            {
                printf("#\t");
            }
            else 
            {
                printf("%d\t",g->Adj[i][j]);
            }
        }
        printf("\n");
    }
   
}
/*-----------------------------深度优先 DFS---------------------------*/
int visited[MAXN]={0};//访问标志位数组，里面各元素的值  0表示还没有被访问   1代表已经被访问了 

/*
    FirstAdjindex:找到第v_index个顶点的第一个邻接点的下标并返回
*/
int FirstAdjindex(Graph *g,int v_index)
{
    int i;
    for(i = 0;i<g->vexnum;i++)
    {
        if(g->Adj[v_index][i] != MAXNUM)
        {
            return i;
        }
    }
    return -1;
}
/*
    NextAdjindex:从图g中找出第v_index个顶点的邻接点w后面的邻接点
*/
int NextAdjindex(Graph *g,int v_index,int w)
{
    int i;
    for(i = w+1;i<g->vexnum;i++)
    {
        if(g->Adj[v_index][i] != MAXNUM)
        {
            return i;
        }
    }
    return -1;
}
/*
    从图g中的下标为v_index的顶点出发，以深度优先的算法遍历图
*/
void DFS(Graph *g,int v_index)
{
    /*step1:先访问自己*/
    visited[v_index] = 1;
    printf("%c ",g->V[v_index]);
    /*step2:找到v的一个临界点的下标w，如果未被访问，去访问它*/
    int w;
    for(w=FirstAdjindex(g,v_index);w!=-1;w=NextAdjindex(g,v_index,w))
    {
        if(visited[w] == 0)
        {
            DFS(g,w);
        }
    }
}

/*

*/
void DFS_pro(Graph *g,int v_index)
{
    //1.初始化访问数组 == 0
    int i;
    for(i = 0;i<g->vexnum;i++)
    {
       visited[i] = 0; 
    }
    //DFS
    DFS(g,v_index);
    printf("\n");
}
/*-------------------------广度优先算法BFS-----------------------*/
/*
    从图g中的下标为v_index的顶点出发，以广度优先的算法遍历图
*/
void BFS(Graph *g,int vindex)
{
    //1.初始化访问数组 == 0
    int i;
    for(i = 0;i<g->vexnum;i++)
    {
       visited[i] = 0; 
    }    
    Cqueue *cq = InitQueue();//初始化一个队列
    /*访问出发结点并把这个结点的下标入队*/
    visited[vindex] = 1;
    printf("%c ",g->V[vindex]);
    EnQueue(cq,vindex);

    while(!QueueIsEmpty(cq))
    {
        int i = DeQueue(cq);
        int w;
        /*把出队的下标i对应的顶点的所有未被访问的邻接点全部入队*/
        for(w=FirstAdjindex(g,i);w!=-1;w=NextAdjindex(g,i,w))
        {
            if(visited[w] == 0)
            {
                visited[w] = 1;
                printf("%c ",g->V[w]);
                EnQueue(cq,w);
            }
        }
    }

    DestroyQueue(cq);
}