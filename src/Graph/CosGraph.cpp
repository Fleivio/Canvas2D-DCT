#include "CosGraph.h"

CosGraph::CosGraph(vector<double> coefs){
    this->coefs = coefs;
}

double CosGraph::f(double x){
    double y = 0;
    int size = coefs.size();
    
    for(int i = 0; i < size; i++){
        double freq = (i * PI) / (2 * size);
        y += cos(x * freq) * coefs.at(i);
    }

    return y;
}

void CosGraph::draw(){
    CV::color(0, 0 ,0);
    CV::translate(0, 100);
    for(double x = 0; x < coefs.size(); x += 0.005){
        CV::point(x * 50, f(x) * 5);
    }
    CV::translate(0,0);
}
