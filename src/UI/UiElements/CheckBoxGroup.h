/*impementa um grupo de checkbox (impede que mais de uma esteja em check ao mesmo tempo)
variável allow_uncheck controlla se será ou não permitido que nenhuma esteja selecionada*/
#ifndef _CHECKBOX_GROUP_
#define _CHECKBOX_GROUP_

#include "CheckBox.h"
#include "../../Drawer/Drawer.h"
using namespace std;
#include <list>

class CheckBoxGroup
{
private:
    /*deseleciona todas (ignora allow uncheck)*/
    void uncheck_all();

    bool allow_uncheck;

public:
    list<CheckBox *> *checkBoxes;
    ClickableField *field;

    /*cria uma checkboxGroup (recebe field p/ click e lista de checkboxes)*/
    CheckBoxGroup(ClickableField *field, list<CheckBox *> *checkboxes);
    /*cria uma checkboxGroup (recebe field p/ click, lista de checkbox vazia)*/
    CheckBoxGroup(ClickableField *field);
    virtual ~CheckBoxGroup();

    /*adiciona uma nova checkbox na lista*/
    void add_checkbox(CheckBox *checkbox);
    /*itera sobre as checkbox filhas p/ verifica seleção*/
    void on_click(float x, float y);
    /*chama on_cick() se o ponto estiver dentro de sua field*/
    bool verify_on_click(float x, float y);
    /*altera allow_uncheck*/
    void set_allow_uncheck(bool allow);
    /*seta a checkbox filha a estar selecionada (util p/ definir estados iniciais)*/
    void set_checked_child(CheckBox *child);
    /*retorna a checkbox atualmente selecionada, nulltpr se nenhuma*/
    CheckBox *get_checked();

    /*itera sobre suas filhas checkbox p/ desenhar*/
    virtual void draw();
};

#endif