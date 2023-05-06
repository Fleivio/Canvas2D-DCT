#include "Bar.h"

float Bar::defaultGap = 5;

Bar::Bar(float x1, float y1, float x2, float y2) : Button(x1, y1, x2, y2)
{
    field->set_border(true);
    totalW = x2 - x1;
    totalH = y2 - y1;
}

bool Bar::verify_on_click(float x, float y)
{
    if (field->is_point_inside(x, y))
    {
        on_click(x, y);
        return true;
    }
    return false;
}