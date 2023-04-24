#include "CosineTransformer.h"

vector<double> CosineTransformer::DCT(const vector<double> input){
    int m = input.size();
    vector<double> F;

    for(int i = 0; i < m; i++){
        
        double sum = 0;
        double c = (i == 0) ? sqrt(0.5) : 1;

        for(int j = 0; j < m; j++){
            sum += input.at(j) * cos((2 * j + 1) * i * PI / (2 * m));
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
            sum += input.at(j) * cos((2 * i + 1) * j * PI / (2 * m)) * c;
        }

        f.push_back(sum * sqrt(2.0 / m));
    }

    return f;
}
