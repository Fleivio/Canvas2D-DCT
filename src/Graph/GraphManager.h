#ifndef _GRAPH_MANAGER_
#define _GRAPH_MANAGER_

#include "Graph.h"
#include "GraphDrawer.h"

class GraphManager{

    public:
        vector<Graph*> *graphs;

        GraphManager();
        GraphManager(vector<Graph*> graphs);

        void add_graph(Graph* g);
        void draw();
};

#endif