/*implementa a classe de um botão genérico
possui uma lista de callbacks, uma label e uma clickable field*/
#ifndef _BUTTON_
#define _BUTTON_

#include <functional>
#include <list>
#include <string>
using namespace std;

#include "../Clickable/ClickableCircle.h"
#include "../Clickable/ClickableRect.h"

class Button
{
protected:
    list<function<void()>> *callback;

public:
    string label;
    ClickableField *field;

    /*cria botão a partir de um field retangular, label = ""*/
    Button(float x1, float y1, float x2, float y2);
    /*construtor, recebe field e label*/
    Button(ClickableField *field, string label);
    /*contrutor, recebe field, label = ''*/
    Button(ClickableField *field);

    virtual ~Button();

    /*adiciona um callback na lista*/
    void add_callback(function<void()> callback);
    /*chama seus callbacks*/
    virtual void on_click();
    /*verifica se o ponto está dentro, e se for o caso, chama callbacks*/
    virtual bool verify_on_click(float x, float y);
    /*recebe uma nova label*/
    void set_label(string label);
};

#endif
