/*cria uma classe abstrata ClickableField, filha de Colored Shape
Esta classe será usada dentro de botões e checkbox para verificar clicks
Ela poderia ser facilmente substituida por uma Figure, mas evitei para maior simplicidade e especialização*/
#ifndef _CLICKABLE_FIELD_
#define _CLICKABLE_FIELD_

#include "../../Basic/ColoredShape.h"

using namespace std;
#include <functional>

class ClickableField : public ColoredShape
{
public:
    virtual ~ClickableField() = default;

    /*verifica se o ponto está dentro*/
    virtual bool is_point_inside(float x, float y) = 0;
    /*verifica se o ponto está dentro*/
    virtual bool is_point_inside(Vector2 &vec) = 0;
};

#endif