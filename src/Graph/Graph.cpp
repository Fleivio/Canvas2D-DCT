#include "Graph.h"

Graph::Graph(string name, Vector2 *p1, Vector2 *p2, Color *c1, Color *c2, PointSet *points) : ColoredShape(c1){
    this->p1 = p1;
    this->p2 = p2;
    set_border_color(c2);
    set_border(true);
    this->points = points;
    this->name = name;
}

Graph::Graph(string name, Vector2 *p1, Vector2 *p2, PointSet *points) : ColoredShape(0,0,0){
    this->p1 = p1;
    this->p2 = p2;
    set_border_color(1,0,0);
    set_border(true);
    this->points = points;
    this->name = name;
}

void Graph::set_points(PointSet* points){
    delete this->points;
    this->points = points;
}

