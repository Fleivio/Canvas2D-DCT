/*implementa uma classe p/ slider
retorna o valor sempre em pocentagem*/
#ifndef _SLIDER_
#define _SLIDER_

#include "../Clickable/ClickableCircle.h"
#include "../Clickable/ClickableRect.h"
#include "Button.h"

class Slider : public Button
{
private:
    /*raio da bola de seleção*/
    static int defaultRadius;

public:
    /*tamanho inicial e final do slider*/
    Vector2 *initial, *final;
    /*esfera de seleção*/
    ClickableCircle *actual;
    /*field de click*/
    ClickableRect *fullSlider;

    /*contrutor (seta o field/range total)*/
    Slider(float ix, float iy, float fx, float fy);
    ~Slider();
    /*retorna o valor em porcentagem da distacia do circulo de seleção dentro do field inteiro*/
    int calc_value();
    /*seta o valor selecionado (muda a posição de actual)*/
    void set_value(float val);
    /*trata click na posição x y, seta a esfera no local adequado*/
    void on_click(float x, float y);
};

#endif