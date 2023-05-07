#ifndef _COSINE_TRANSFORMER_
#define _COSINE_TRANSFORMER_

/*classe responsável pela geração de vetores
Aplica DCT e IDCT, quantizacao e dequantização, também gera valores aleatórios e calcula a diferença*/

#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

#define PI_ 3.14159265358979323846

class CosineTransformer {
    private:
        static double quantizationFactor;
        static double quantizationVector(int i);

    public:
        //retorna o vetor de amplitudes, aplica a DCT
        static vector<double> DCT(const vector<double> input);

        //retorna o vetor próximo do original, aplica a IDCT
        static vector<double> IDCT(const vector<double> input);

        //aplica a quantização
        static vector<double> QUANT(const vector<double> input);

        //aplica a desquantização
        static vector<double> DEQUANT(const vector<double> input);

        //calcula a diferenca entre dois vetores
        static vector<double> DIFF(const vector<double> v1, const vector<double> v2);

        //retorna um novo vetor com os valores aleatórios
        static vector<double> RAND(int n);

        //retorna um novo vetor com valores associados ao seno
        static vector<double> SIN(int n);

        //seta o valor de quantizacao
        static void set_quantization_factor(double quantizationFactor);
        //retorna o valor de quantizacao
        static double get_quantization_factor();

};

#endif
