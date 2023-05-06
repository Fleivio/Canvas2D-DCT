/*Implamenta a classe que desenha coisas na tela
tanto figuras, quanto botões da interface*/

#ifndef _DRAWER_
#define _DRAWER_

#include "../gl_canvas2d.h"
#include "../UI/Clickable/ClickableCircle.h"
#include "../UI/Clickable/ClickableRect.h"

#include "../UI/UiElements/Button.h"
#include "../UI/UiElements/CheckBox.h"
#include "../UI/UiElements/Slider.h"

using namespace std;

class Drawer
{
public:

    /*desenha field na tela, converte para rect ou circle*/
    static void draw(ClickableField *field);
    /*desenha circle na tela*/
    static void draw(ClickableCircle *circle);
    /*desenha rect na tela*/
    static void draw(ClickableRect *rect);
    /*desenha button na tela (field e label)*/
    static void draw(Button *button);
    /*desenha checkbox na tela (seleção e label)*/
    static void draw(CheckBox *checkbox);
    /*desenha slider na tela (seu circle e seu corpo (fullslider))*/
    static void draw(Slider *slider);
    /*desenha uma label na tela, calcula o centro baseado em field*/
    static void draw(string label, ClickableField *field);
};

#endif
