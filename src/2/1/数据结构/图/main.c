#include "graph.h"

int main()
{
    Graph *g = Create_graph();
    print_graph(g);
    BFS(g,0);

    return 0;
}"
