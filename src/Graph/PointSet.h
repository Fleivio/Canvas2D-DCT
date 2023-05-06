#ifndef _PointSet_
#define _PointSet_

/*conjunto de pontos*/

#include "../Basic/Vector2.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class PointSet
{
public:
    vector<double> *points;

    // construtor, recebe lista de pontos
    PointSet(vector<double> points);
    PointSet();

    ~PointSet();

    // adicina um novo ponto ao gráfico
    void add_point(double point);

    // retorna o valor maximo
    double get_max_value();

    // retorna o valor minimo
    double get_min_value();

    // retorna o range de valores
    double get_interval();

    // retorno a numero de valores
    int get_n_values();

    // printa na tela os valores
    void print();
};

#endif