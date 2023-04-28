#ifndef _COSINE_TRANSFORMER_
#define _COSINE_TRANSFORMER_

#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define PI 3.14159265358979323846

class CosineTransformer {
    private:
        static int nLevels;
    public:
        static vector<double> DCT(const vector<double> input);
        static vector<double> IDCT(const vector<double> input);
        static vector<double> QUANT(const vector<double> input);
        static vector<double> DEQUANT(const vector<double> input);
};

#endif
