#ifndef _GRAPH_
#define _GRAPH_

#include "../Basic/Vector2.h"
#include <vector>
using namespace std;

class Graph{
    public:
        vector<double> *points;

        Graph(vector<double> points);
        Graph();

        void add_point(double point);
};

#endif