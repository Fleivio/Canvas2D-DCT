#include "Panel.h"

extern int screenHeight;

int Panel::width = 150;

Panel::Panel(DCTController *controller)
{
    this->controller = controller;
    set_up_field();
}

void Panel::handle_click(float x, float y)
{
    if (field->is_point_inside(x, y))
    {
        //controle de botões
    }
}

void Panel::handle_hold(float x1, float y1, float x2, float y2)
{
    if (field->is_point_inside(x1, y1))
    {
        //controle de botões
    }
}

void Panel::draw()
{

}


void Panel::set_up_field()
{
    field = new ClickableRect(0, 0, width, 1000);
    field->set_border(true);
    field->set_border_color(0, 0, 0);
    field->set_color(0.9, 0.9, 0.9);
}