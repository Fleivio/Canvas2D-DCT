#ifndef _GRAPH_DRAWER_
#define _GRAPH_DRAWER_

/*classe que sabe desenhar gráficos*/

#include "Graph.h"
#include "PointSet.h"
#include "../gl_canvas2d.h"

#include <vector>
#include <string>
#include <sstream>
using namespace std;

class GraphDrawer
{
private:
    static int pointDiv, pointRadius;
    static Color* backgroundColor;
    static bool showPoints;

    static void draw_point(float x, float y);
    static void drawAxis(double offset, double width, double yInc, double max, double min);
    static string toScientificNotation(double value);
public:
    //desenha o grafico
    static void draw(Graph *graph);

};

#endif