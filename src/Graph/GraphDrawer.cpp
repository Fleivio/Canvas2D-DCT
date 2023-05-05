#include "GraphDrawer.h"

int GraphDrawer::pointDiv = 4;
int GraphDrawer::pointRadius = 5;
Color* GraphDrawer::backgroundColor = new Color(0.9, 0.9, 0.9);

void GraphDrawer::draw_point(float x, float y){
    CV::circleFill(x, y, pointRadius, pointDiv);
}

string GraphDrawer::toScientificNotation(int value){
    if(value == 0) return "0";

    int exp = floor(log10(abs(value)));
    int digit = floor(value / pow(10, exp));

    stringstream s;
    s << digit;
    s << "e" << exp;
    return s.str();
}


void GraphDrawer::drawAxis(double offset, double width, double yInc, double max, double min){
    double range = abs(max - min);
    int magnitude = pow(10, floor(log10(range)));

    int fstline = ceil(min / magnitude) * magnitude;

    CV::color(0);
    for(int i = fstline; i <= max; i += magnitude){
        if(i % 5 == 0 /*|| i % 2 == 0*/){
            CV::line(0, (i + yInc) * offset, width, (i + yInc) * offset);
            cout << i << "\n";
            CV::small_text(-5, (i + yInc) * offset + 2, toScientificNotation(i).c_str());
        }
    }
}

void GraphDrawer::draw(Graph *graph)
{
    PointSet *pointSet = graph->points;
    vector<double> *values = pointSet->points;

    int n = pointSet->get_n_values();
    double minValue = pointSet->get_min_value();
    double maxValue = pointSet->get_max_value();

    double graphWidth = graph->p2->x - graph->p1->x;
    double graphHeight = graph->p2->y - graph->p1->y;

    double yIncrement = -minValue;
    double xIncrement = graphWidth / n;
    double offsetMult = -graphHeight / (maxValue + yIncrement);

    cout << yIncrement << "\n";
    cout << xIncrement << "\n";
    cout << offsetMult << "\n";

    backgroundColor->apply_color();
    CV::rectFill(*(graph->p1), *(graph->p2));
    CV::color(0);
    CV::rect(*(graph->p1), *(graph->p2));

    CV::translate(graph->p1->x, graph->p2->y);

    drawAxis(offsetMult, graphWidth, yIncrement, maxValue, minValue);

    int i = 0;
    double y1 = (values->at(i) + yIncrement) * offsetMult;

    graph->color->apply_color();
    draw_point(0, y1);

    double y2 = 0;

    for (; i < n - 1; i++)
    {
        y2 = (values->at(i + 1) + yIncrement) * offsetMult;

        graph->borderColor->apply_color();
        CV::line(i * xIncrement, y1, (i + 1) * xIncrement, y2);

        graph->color->apply_color();
        draw_point((i + 1) * xIncrement, y2);

        y1 = y2;
    }

    CV::color(0, 0, 0);
    CV::text(0, -graphHeight - 5, graph->name.c_str());

    CV::translate(-graph->p1->x, -graph->p2->y);
}