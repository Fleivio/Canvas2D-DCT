#ifndef _COSINE_TRANSFORMER_
#define _COSINE_TRANSFORMER_

#include <vector>
#include <cmath>
using namespace std;

#define PI 3.14159265358979323846

class CosineTransformer {
    public:
        static vector<double> DCT(const vector<double> input);
        static vector<double> IDCT(const vector<double> input);
};

#endif
