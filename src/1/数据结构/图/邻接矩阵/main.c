#include "graph.h"

int main()
{
    Graph *g = Create_graph();
    print_graph(g);
    print_dist(g,0);
    print_path(g,0);

    return 0;
}