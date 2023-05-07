#ifndef _DCT_CONT_
#define _DCT_CONT_

/*classe que mantem os gráficos de saída a cada aplicação da DCT, se comunica com a criação de arquivos e odena
o print dos graficos*/

using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include "../FileManager/FileHandler.h"
#include "CosineTransformer.h"
#include "../Graph/Graph.h"
#include "../Graph/GraphDrawer.h"

using namespace std;

class DCTController{
    private:
        static string input;
        static string output;

        static float xSpace;
        static float ySpace;
        static float graphH;
        static float graphW;
        static float graphGap;

        vector<char> double_to_char(vector<double> ds);
        vector<double> char_to_double(vector<char> cs);

        void att_graphs(vector<double> input);
        void set_graphs();

        Graph *original;
        Graph *dct;
        Graph *quant;
        Graph *dequant;
        Graph *idct;
        Graph *diff;

    public:
        DCTController();
        ~DCTController();

        //salva a saída do programa em output
        void save_output();

        //salva a entrada do programa em input
        void load_from_actual();

        //acessa o arquivo input e aplica DCT
        void DCT_from_file();

        //gera um vetor aleatorio e aplica DCT
        void DCT_from_rand(int n);

        //gera uma funcao seno com n entradas
        void DCT_from_sin(int n);

        //seta o valor de quantizacao
        void set_quantization_factor(double q);

        //retorna o valor de quantizacao
        double get_quantization_factor();

        //desenha os gráficos
        void draw();
};

#endif
