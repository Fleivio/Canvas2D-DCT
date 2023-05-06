#include "CosineTransformer.h"

double CosineTransformer::quantizationFactor = 0.1;

vector<double> CosineTransformer::DCT(const vector<double> input){
    int m = input.size();
    vector<double> F;

    for(int i = 0; i < m; i++){

        double sum = 0;
        double c = (i == 0) ? sqrt(0.5) : 1;

        for(int j = 0; j < m; j++){
            sum += input.at(j) * cos((2 * j + 1) * i * PI_ / (2 * m));
        }

        sum *= c;

        F.push_back(sum * sqrt(2.0 / m));
    }

    return F;
}

vector<double> CosineTransformer::IDCT(const vector<double> input){
    int m = input.size();
    vector<double> f;

    for(int i = 0; i < m; i++){

        double sum = 0;

        for(int j = 0; j < m; j++){
            double c = (j == 0) ? sqrt(0.5) : 1;
            sum += input.at(j) * cos((2 * i + 1) * j * PI_ / (2 * m)) * c;
        }

        f.push_back(sum * sqrt(2.0 / m));
    }

    return f;
}

double CosineTransformer::quantizationVector(int i){
    return 1.0 + (i+1) * quantizationFactor;
}

vector<double> CosineTransformer::QUANT(const vector<double> input){
    vector<double> quantized(input.size());
    for(int i = 0; i < (int)input.size(); i++){
        quantized.at(i) = round(input.at(i) / quantizationVector(i));
    }

    return quantized;
}

vector<double> CosineTransformer::DEQUANT(const vector<double> input){
    vector<double> dequantized(input.size());
    for(int i = 0; i < (int)input.size(); i++){
        dequantized.at(i) = input.at(i) * quantizationVector(i);
    }
    return dequantized;
}

vector<double> CosineTransformer::DIFF(const vector<double> v1, const vector<double> v2){
    vector<double> vec;

    for(int i = 0; i < (int) v1.size() && i < (int) v2.size(); i++){
        vec.push_back(v1.at(i) - v2.at(i));
    }
    return vec;
}

vector<double> CosineTransformer::RAND(int n){
    vector<double> result(n);
    generate(result.begin(), result.end(), std::rand);

    return result;
}

void CosineTransformer::set_quantization_factor(double q){
    quantizationFactor = q;
}
