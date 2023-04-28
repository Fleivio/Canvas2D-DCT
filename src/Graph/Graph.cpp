#include "Graph.h"

Graph::Graph(){
    points = new vector<double>();
}

Graph::Graph(vector<double> points){
    this->points = new vector<double>(points);
}

void Graph::add_point(double val){
    points->push_back(val);
}