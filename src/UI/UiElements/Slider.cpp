#include "Slider.h"

int Slider::defaultRadius = 5;

Slider::Slider(float ix, float iy, float fx, float fy)
{
    initial = new Vector2(ix, iy);
    final = new Vector2(fx, fy);
    actual = new ClickableCircle(defaultRadius, ix, iy + (fy - iy) / 2);
    fullSlider = new ClickableRect(ix, iy, fx, fy);
    fullSlider->set_color(0, 0.3, 0.2);
    actual->set_color(0, 0, 0);
}

Slider::~Slider()
{
    delete initial;
    delete final;
    delete actual;
}

int Slider::calc_value()
{
    if (final->x == initial->x)
        return 100;
    return (int)(100 * (actual->v1->x - initial->x)) / (final->x - initial->x);
}

void Slider::on_click(float x, float y)
{
    actual->v1->x = x;
}

void Slider::set_value(float value)
{
    actual->v1->x = initial->x + (final->x - initial->x) * value;
}