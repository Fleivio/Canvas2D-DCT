/*classe mãe de Botões, CheckBoxes, Fields, Sliders e CheckBoxGroups
útil para separa o que cada trecho da interface significa*/
#ifndef _BAR_
#define _BAR_

#include "Button.h"

class Bar : public Button
{
protected:
    float totalW;
    float totalH;
    static float defaultGap;

public:
    /*contrutor, cria um field retangular*/
    Bar(float x1, float y1, float x2, float y2);

    /*desenha bar e seus elementos filhos*/
    virtual void draw() = 0;
    /*repassa o click para seus elementos filhos*/
    virtual void on_click(float x, float y) = 0;
    /*verifica se x,y esta dentro de seu field, se estiver chama on_click()*/
    bool verify_on_click(float x, float y) override;

    /*seta seus filhos nas posições adequadas (dentro de si)
    geralmente funções longas e tristes*/
    virtual void set_up_childs(float x1, float y1, float x2, float y2) = 0;
};

#endif