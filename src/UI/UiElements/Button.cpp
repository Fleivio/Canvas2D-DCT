#include "Button.h"

Button::Button(ClickableField *field, string label)
{
    this->field = field;
    this->label = label;
    callback = new list<function<void()>>();
}

Button::Button(ClickableField *field)
{
    this->field = field;
    this->label = "";
    callback = new list<function<void()>>();
}

Button::Button(float x1, float y1, float x2, float y2)
{
    this->field = new ClickableRect(x1, y1, x2, y2);
    this->label = "";
    callback = new list<function<void()>>();
}

void Button::set_label(string label)
{
    this->label = label;
}

Button::~Button()
{
    delete field;
}

void Button::on_click()
{
    for (auto e : *callback)
    {
        e();
    }
}

void Button::add_callback(function<void()> f)
{
    callback->push_back(f);
}

bool Button::verify_on_click(float x, float y)
{
    if (field->is_point_inside(x, y))
    {
        on_click();
        return true;
    }
    return false;
}
