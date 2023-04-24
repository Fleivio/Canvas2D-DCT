/*Implementa uma classe para vetor de duas dimensões, útil para pontos*/
#ifndef __VECTOR_2_H__
#define __VECTOR_2_H__

#include <math.h>
class Vector2
{
public:
    float x, y;

    /*cria Vector(0,0)*/
    Vector2();
    /*cria um vetor com coordenadas x,y*/
    Vector2(float x, float y);

    /*seta uma nova coordenada*/
    void set(float x, float y);

    /*seta novas coordenadas iguais a vec*/
    void set(Vector2 &vec);

    /*normaliza o vetor*/
    void normalize();

    /*verifica a igualdade entre dois vetores*/
    bool equals(Vector2 &vec);

    /*verifica a distancia entre dois pontos*/
    float distance(Vector2 v);

    /*verifica a distancia entre dois pontos*/
    float distance(float x, float y);

    /*retorna uma cópia do vetor original*/
    Vector2 *copy();
};

#endif
