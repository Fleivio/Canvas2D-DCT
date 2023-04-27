#ifndef _GRAPH_
#define _GRAPH_

#include "../Basic/Vector2.h"
#include <list>
using namespace std;

class Graph{
    public:
        list<double> *points;

        Graph(list<double> points);
        Graph();

        void add_point(double point);
};

#endif