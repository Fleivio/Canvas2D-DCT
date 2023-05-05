#include "GraphDrawer.h"

int GraphDrawer::pointDiv = 4;
int GraphDrawer::pointRadius = 5;
Color* GraphDrawer::backgroundColor = new Color(0.9, 0.9, 0.9);
bool GraphDrawer::showPoints = false;

void GraphDrawer::draw_point(float x, float y){
    CV::circleFill(x, y, pointRadius, pointDiv);
}

string GraphDrawer::toScientificNotation(double value){
    if(value == 0) return "0";
    if(abs(value) >= 1 && abs(value) < 1000) return to_string((int)value);

    int exp = floor(log10(abs(value)));
    int digit = floor(value / pow(10, exp));

    stringstream s;
    s << digit;
    s << "e" << exp;
    return s.str();
}

double round_10(double valor) {
    if (valor == 0)
        return 0;
    
    double expoente = floor(log10(abs(valor)));
    double fator_escala = pow(10, expoente);
    double valor_arredondado = round(valor / fator_escala);
    if (valor_arredondado == 10) {
        valor_arredondado = 1;
        expoente += 1;
    }
    return copysign(pow(10, expoente), valor_arredondado);
}

void GraphDrawer::drawAxis(double offset, double width, double yInc, double max, double min){

    double range = abs(max - min);
    double interval = round_10(range);

    if(range/interval < 5) interval /= 2;

    double fstline = ceil(min/interval) * interval;
    double lstline = floor(max/interval) * interval;

    for(double i = fstline; i <= lstline; i += interval){
        CV::color(0.6, 0.6, 0.6);
        CV::line(0, (i + yInc) * offset, width, (i + yInc) * offset);
        CV::color(0.4, 0.4, 0.4);
        CV::small_text(-15, (i + yInc) * offset + 2, toScientificNotation(i).c_str());
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
    double xIncrement = graphWidth / (n-1);
    double offsetMult = -graphHeight / (maxValue + yIncrement);


    backgroundColor->apply_color();

    CV::translate(graph->p1->x, graph->p2->y);

    CV::rectFill(0, 0, graphWidth, -graphHeight);
    CV::color(0);
    CV::rect(0, 0, graphWidth, -graphHeight);

    drawAxis(offsetMult, graphWidth, yIncrement, maxValue, minValue);

    int i = 0;
    double y1 = (values->at(i) + yIncrement) * offsetMult;

    if(showPoints){
        graph->color->apply_color();
        draw_point(0, y1);
    }

    double y2 = 0;

    for (; i < n - 1; i++)
    {
        y2 = (values->at(i + 1) + yIncrement) * offsetMult;

        graph->borderColor->apply_color();
        CV::line(i * xIncrement, y1, (i + 1) * xIncrement, y2);

        if(showPoints){
            graph->color->apply_color();
            draw_point((i + 1) * xIncrement, y2);
        }

        y1 = y2;
    }

    CV::color(0, 0, 0);
    CV::text(0, -graphHeight - 5, graph->name.c_str());

    CV::translate(-graph->p1->x, -graph->p2->y);
}