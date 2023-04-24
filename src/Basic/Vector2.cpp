#include "Vector2.h"

Vector2::Vector2()
{
    x = y = 0;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Vector2::set(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Vector2::set(Vector2 &vec)
{
    set(vec.x, vec.y);
}

void Vector2::normalize()
{
    float norm = (float)sqrt(x * x + y * y);

    if (norm == 0.0)
    {
        x = 1;
        y = 1;
        return;
    }

    x /= norm;
    y /= norm;
}

float Vector2::distance(float x, float y)
{
    return (float)sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
}

float Vector2::distance(Vector2 v)
{
    return distance(v.x, v.y);
}

Vector2 *Vector2::copy()
{
    return new Vector2(x, y);
}

bool Vector2::equals(Vector2 &vec)
{
    return x == vec.x && y == vec.y;
}