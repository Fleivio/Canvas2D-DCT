#include "ColoredShape.h"

Color *ColoredShape::defaultBorderColor = new Color(0, 0, 0);
Color *ColoredShape::defaultColor = new Color((float)0.5, 0.5, 0.5);

void ColoredShape::set_up_border()
{
    this->hasBorder = false;
    this->borderColor = defaultBorderColor->copy();
}

ColoredShape::ColoredShape(Color *c, bool isFilled)
{
    color = c->copy();
    this->isFilled = isFilled;
    set_up_border();
}

ColoredShape::ColoredShape(float r, float g, float b, bool isFilled)
{
    color = new Color(r, g, b);
    this->isFilled = isFilled;
    set_up_border();
}

ColoredShape::ColoredShape(float r, float g, float b) : ColoredShape(r, g, b, true) {}

ColoredShape::ColoredShape(Color *c) : ColoredShape(c, true) {}

ColoredShape::ColoredShape(bool isFilled) : ColoredShape(defaultColor, isFilled) {}

ColoredShape::ColoredShape() : ColoredShape(defaultColor, true) {}

ColoredShape::~ColoredShape()
{
    delete borderColor;
    delete color;
}

void ColoredShape::set_border(bool hasBorder)
{
    this->hasBorder = hasBorder;
}

void ColoredShape::set_border_color(float r, float g, float b)
{
    delete borderColor;
    this->borderColor = new Color(r, g, b);
}

void ColoredShape::set_border_color(Color *c)
{
    delete borderColor;
    this->borderColor = c->copy();
}

void ColoredShape::set_color(float r, float g, float b)
{
    delete color;
    color = new Color(r, g, b);
}

void ColoredShape::set_color(Color *c)
{
    delete color;
    color = c->copy();
}

void ColoredShape::set_filled(bool isFilled)
{
    this->isFilled = isFilled;
}