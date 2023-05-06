#ifndef _DCT_CONT_
#define _DCT_CONT_

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


        void save_output();
        void DCT_from_file();
        void DCT_from_rand(int n);
        void set_quantization_factor(double q);
        double get_quantization_factor();
        void draw();
};

#endif
