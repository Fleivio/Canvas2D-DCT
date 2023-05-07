/*implementa uma CheckBox : botão cujo callback inverte um booleano (isChecked)
possui campos especiais para a cor que ajudam a identificar se está ou não checkada*/
#ifndef _CHECKBOX_
#define _CHECKBOX_

#include "Button.h"

class CheckBox : public Button
{
public:
    bool isChecked;
    Color *selectedColor;
    Color *unSelectedColor;

    /*cria checkbox recebe field p click e label. cor = default*/
    CheckBox(ClickableField *field, string label);
    /*cria checkbox recebe field p click, label e cor especial p seleção*/
    CheckBox(ClickableField *field, string label, Color *selectionColor);
    ~CheckBox();

    /*seta a checagem da checkbox*/
    void set_checked(bool isChecked);

    /*seta a cor para caso a checkbox esteja selecionada*/
    void set_selected_color(Color *color);

    void set_selected_color(float r, float g, float b);


    /*seta a cor para caso a checkbox não esteja selecionada*/
    void set_unselected_color(Color *color);
    void set_unselected_color(float r, float g, float b);

};

#endif