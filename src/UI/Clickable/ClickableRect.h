/*classe filha de Clickablefield que implementa clicks em um retangulp*/
#ifndef _CLICKABLE_RECT_
#define _CLICKABLE_RECT_

#include "./ClickableField.h"
#include "../../Basic/Vector2.h"

class ClickableRect : public ClickableField
{
public:
    Vector2 *v1, *v2;

    /*cria o retangulo (recebe dois vértices)*/
    ClickableRect(float x1, float y1, float x2, float y2);
    ~ClickableRect();

    /*verifica se o ponto está dentro do reatngulo*/
    bool is_point_inside(float x, float y) override;
    /*verifica se o ponto está dentro do retangulo*/
    bool is_point_inside(Vector2 &vec) override;
};

#endif