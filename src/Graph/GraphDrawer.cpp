#include "GraphDrawer.h"

void GraphDrawer::draw(Graph *graph)
{
    PointSet *pointSet = graph->points;
    vector<double> *values = pointSet->points;

    int n = pointSet->get_n_values();
    double minValue = pointSet->get_min_value();
    double maxValue = pointSet->get_max_value();
    double interval = pointSet->get_interval();

    double graphWidth = graph->p2->x - graph->p1->x;
    double graphHeight = graph->p2->y - graph->p1->y;

    double yIncrement = -minValue;
    double xIncrement = graphWidth / n;
    double offsetMult = -graphHeight / (maxValue + yIncrement);

    cout << yIncrement << "\n";
    cout << xIncrement << "\n";
    cout << offsetMult << "\n";

    CV::color(0.9, 0.9, 0.9);
    CV::rectFill(*(graph->p1), *(graph->p2));
    CV::translate(graph->p1->x, graph->p2->y);

    int i = 0;
    double y1 = (values->at(i) + yIncrement) * offsetMult;

    graph->color->apply_color();
    CV::circleFill(0, y1, 5, 4);

    double y2 = 0;

    for (; i < n - 1; i++)
    {
        y2 = (values->at(i + 1) + yIncrement) * offsetMult;

        graph->borderColor->apply_color();
        CV::line(i * xIncrement, y1, (i + 1) * xIncrement, y2);

        graph->color->apply_color();
        CV::circleFill((i + 1) * xIncrement, y2, 5, 4);

        y1 = y2;
    }

    CV::color(0, 0, 0);
    CV::text(0, -graphHeight - 5, graph->name.c_str());

    CV::translate(-graph->p1->x, -graph->p2->y);
}