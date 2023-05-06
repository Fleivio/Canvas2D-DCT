#ifndef _DCT_CONT_
#define _DCT_CONT_

using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include "../FileManager/FileHandler.h"
#include "../Graph/GraphManager.h"
#include "CosineTransformer.h"

using namespace std;

class DCTController{
    private:
        static string input;
        static string output;

        vector<char> double_to_char(vector<double> ds);
        vector<double> char_to_double(vector<char> cs);

        void init_graphs(vector<double> input);
        GraphManager* gm;
        vector<double> original;
    public:
        DCTController();
        ~DCTController();


        void save_output(vector<double> vec);
        void DCT_from_file();
        void DCT_from_rand(int n);
        void set_quantization_factor(double q);
        void draw();
};

#endif
