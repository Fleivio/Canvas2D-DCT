#include "Drawer.h"

void Drawer::draw(ClickableCircle *circle)
{
    circle->color->apply_color();
    if (circle->isFilled)
    {
        CV::circleFill(*(circle->v1), circle->radius, 30);
    }
    else
    {
        CV::circle(*(circle->v1), circle->radius, 30);
    }

    if (circle->hasBorder)
    {
        circle->borderColor->apply_color();
        CV::circle(*(circle->v1), circle->radius, 30);
    }
}

void Drawer::draw(ClickableRect *rect)
{
    rect->color->apply_color();
    if (rect->isFilled)
    {
        CV::rectFill(*(rect->v1), *(rect->v2));
    }
    else
    {
        CV::rect(*(rect->v1), *(rect->v2));
    }

    if (rect->hasBorder)
    {
        rect->borderColor->apply_color();
        CV::rect(*(rect->v1), *(rect->v2));
    }
}

void Drawer::draw(ClickableField *field)
{
    if (ClickableCircle *c = dynamic_cast<ClickableCircle *>(field))
        draw(c);
    else if (ClickableRect *r = dynamic_cast<ClickableRect *>(field))
        draw(r);
}

void Drawer::draw(string label, ClickableField *field)
{
    CV::color(0, 0, 0);
    if (ClickableCircle *c = dynamic_cast<ClickableCircle *>(field))
    {
        CV::text(c->v1->x + 2 * c->radius, c->v1->y + c->radius, label.c_str());
    }
    else if (ClickableRect *r = dynamic_cast<ClickableRect *>(field))
    {
        CV::text(r->v1->x, r->v2->y, label.c_str());
    }
}

void Drawer::draw(Button *button)
{
    draw(button->field);
    draw(button->label, button->field);
}

void Drawer::draw(CheckBox *checkbox)
{
    if (checkbox->isChecked)
    {
        checkbox->field->set_color(checkbox->selectedColor);
        draw(checkbox->field);
    }
    else
    {
        checkbox->field->set_color(checkbox->unSelectedColor);
        draw(checkbox->field);
    }
    draw(checkbox->label, checkbox->field);
}

void Drawer::draw(Slider *slider)
{
    draw(slider->fullSlider);
    draw(slider->actual);
}