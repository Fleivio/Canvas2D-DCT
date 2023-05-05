/*classe estatica que acessa o arquivo salvo e escreve nele*/
#ifndef _SAVER_
#define _SAVER_

using namespace std;
#include <vector>
#include <string>
#include <fstream>

class FileHandler
{
public:
    /*escreve o vetor de bytes no arquivo*/
    static void save(const vector<char> &vec, const string &fileName);
    /*carrega o vetor de bytes do arquivo*/
    static vector<char> load(const string &fileName);
};

#endif