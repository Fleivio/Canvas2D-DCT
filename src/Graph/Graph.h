#ifndef _GRAPH_
#define _GRAPH_

#include "../Basic/ColoredShape.h"
#include "PointSet.h"
#include "../Basic/Vector2.h"
using namespace std;
#include <string>

class Graph : public ColoredShape
{

public:
    Vector2 *p1, *p2;
    PointSet *points;
    string name;
    Graph(string name, Vector2 *p1, Vector2 *p2, Color *c1, Color *c2, PointSet *points);
};

#endif