#ifndef _GRAPH_DRAWER_
#define _GRAPH_DRAWER_

#include "Graph.h"
#include "PointSet.h"
#include "../gl_canvas2d.h"

#include <vector>
using namespace std;

class GraphDrawer
{
public:
    static void draw(Graph *graph);
};

#endif