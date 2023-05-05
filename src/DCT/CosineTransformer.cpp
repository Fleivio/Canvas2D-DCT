#include "CosineTransformer.h"

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

int CosineTransformer::nLevels = 8;

vector<double> CosineTransformer::QUANT(const vector<double> input){
    double minVal = *min_element(input.begin(), input.end());
    double maxVal = *max_element(input.begin(), input.end());
    double step = (maxVal - minVal) / nLevels;

    vector<double> quantized;
    for(auto val : input){
        quantized.push_back( floor((val - minVal) / step) );
    }
    return quantized;
}

vector<double> CosineTransformer::DEQUANT(const vector<double> input){
    vector<double> dequantized(input.size());
    double step = 2.0 / (nLevels - 1);
    double level;

    for(int i = 0; i < (int)input.size(); i++){
        level = input.at(i) * step - 1;
        dequantized.at(i) = level;
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
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-128, 127);

    for (int i = 0; i < n; ++i) {
        result[i] = static_cast<double>(dis(gen));
    }

    return result;
}
