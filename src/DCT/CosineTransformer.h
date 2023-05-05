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
        //retorna o vetor de amplitudes, aplica a DCT
        static vector<double> DCT(const vector<double> input);

        //retorna o vetor próximo do original, aplica a IDCT
        static vector<double> IDCT(const vector<double> input);

        //aplica a quantização
        static vector<double> QUANT(const vector<double> input);

        //aplica a desquantização
        static vector<double> DEQUANT(const vector<double> input);
};

#endif
