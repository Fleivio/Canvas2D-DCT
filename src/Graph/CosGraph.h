#ifndef _COS_GRAPH_
#define _COS_GRAPH_

#include "../gl_canvas2d.h"
#include <vector>
#include <iostream>
#include "../Basic/ColoredShape.h"
using namespace std;

class CosGraph : public ColoredShape{
    private:
        double f(double x);
    public:
        vector<double> coefs;
        CosGraph(vector<double> coefs);

        void draw();
};


#endif
