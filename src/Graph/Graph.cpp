#include "Graph.h"

Graph::Graph(){
    points = new list<double>();
}

Graph::Graph(list<double> points){
    this->points = new list<double>(points);
}

void Graph::add_point(double val){
    points->push_back(val);
}