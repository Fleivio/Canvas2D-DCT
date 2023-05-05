#ifndef _DCT_CONT_
#define _DCT_CONT_

using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include "FileManager/FileHandler.h"
#include "Graph/GraphManager.h"
#include "DCT/CosineTransformer.h"

using namespace std;

class DCTController{
    private:
        static string input;
        static string output;

        static vector<char> double_to_char(vector<double> ds);
        static vector<double> char_to_double(vector<char> cs);

    public:
        static GraphManager* init_graphs();
        static void save_output(vector<double> vec);
        static vector<double> load_file();
};

#endif