#include "ClickableCircle.h"

ClickableCircle::ClickableCircle(float radius, float x, float y)
{
    this->radius = radius;
    v1 = new Vector2(x, y);
}

ClickableCircle::~ClickableCircle()
{
    delete v1;
}

bool ClickableCircle::is_point_inside(float x, float y)
{
    return v1->distance(x, y) <= radius;
}

bool ClickableCircle::is_point_inside(Vector2 &vec)
{
    return is_point_inside(vec.x, vec.y);
}