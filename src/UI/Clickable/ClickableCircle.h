/*classe filha de Clickablefield que implementa clicks em um circulo*/
#ifndef _CLICKABLE_CIRCLE_
#define _CLICKABLE_CIRCLE_

#include "ClickableField.h"
#include "../../Basic/Vector2.h"

class ClickableCircle : public ClickableField
{
public:
    float radius;
    Vector2 *v1;

    /*contrutor (raio, centro)*/
    ClickableCircle(float radius, float x, float y);
    ~ClickableCircle();

    /*verifica se o ponto está dentro do círuculo*/
    bool is_point_inside(float x, float y) override;
    /*verifica se o ponto está dentro do círuculo*/
    bool is_point_inside(Vector2 &vec) override;
};

#endif