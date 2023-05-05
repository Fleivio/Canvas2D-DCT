#include "PointSet.h"

PointSet::PointSet()
{
    points = new vector<double>();
}

PointSet::PointSet(vector<double> points)
{
    this->points = new vector<double>(points);
}

void PointSet::add_point(double val)
{
    points->push_back(val);
}

double PointSet::get_max_value()
{
    return *max_element(points->begin(), points->end());
}

double PointSet::get_min_value()
{
    return *min_element(points->begin(), points->end());
}

double PointSet::get_interval()
{
    return get_max_value() - get_min_value();
}

int PointSet::get_n_values()
{
    return (int)points->size();
}

void PointSet::print()
{
    for (auto i : *points)
    {
        cout << "[" << i << "]";
    }
    puts("");
}