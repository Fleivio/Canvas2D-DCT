#include "ClickableRect.h"

ClickableRect::ClickableRect(float x1, float y1, float x2, float y2)
{
    v1 = new Vector2(x1, y1);
    v2 = new Vector2(x2, y2);
}

ClickableRect::~ClickableRect()
{
    delete v1;
    delete v2;
}

bool ClickableRect::is_point_inside(float x, float y)
{
    return (x >= v1->x && x <= v2->x) && (y <= v2->y && y >= v1->y);
}
bool ClickableRect::is_point_inside(Vector2 &vec)
{
    return is_point_inside(vec.x, vec.y);
}