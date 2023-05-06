#include "CheckBoxGroup.h"

CheckBoxGroup::CheckBoxGroup(ClickableField *field, list<CheckBox *> *checkBoxes)
{
    this->checkBoxes = checkBoxes;
    this->field = field;
    allow_uncheck = true;
}

CheckBoxGroup::CheckBoxGroup(ClickableField *field)
{
    this->field = field;
    allow_uncheck = true;
    checkBoxes = new list<CheckBox *>();
}

void CheckBoxGroup::add_checkbox(CheckBox *checkbox)
{
    checkBoxes->push_back(checkbox);
}

CheckBoxGroup::~CheckBoxGroup()
{
    for (auto e : *checkBoxes)
    {
        delete e;
    }

    delete checkBoxes;
    delete field;
}

void CheckBoxGroup::uncheck_all()
{
    for (auto e : *checkBoxes)
    {
        e->set_checked(false);
    }
}

void CheckBoxGroup::on_click(float x, float y)
{
    for (auto e : *checkBoxes)
    {
        if (e->verify_on_click(x, y))
        {
            if (e->isChecked)
            {
                uncheck_all();
                e->isChecked = true;
            }

            if (!allow_uncheck)
                e->isChecked = true;
            return;
        }
    }
}

bool CheckBoxGroup::verify_on_click(float x, float y)
{
    if (field->is_point_inside(x, y))
    {
        on_click(x, y);
        return true;
    }

    return false;
}

CheckBox *CheckBoxGroup::get_checked()
{
    for (auto e : *checkBoxes)
    {
        if (e->isChecked)
            return e;
    }
    return nullptr;
}

void CheckBoxGroup::draw()
{
    Drawer::draw(field);
    for (auto e : *checkBoxes)
    {
        Drawer::draw(e);
    }
}

void CheckBoxGroup::set_allow_uncheck(bool allow)
{
    allow_uncheck = allow;
    if (!allow_uncheck)
    {
        if (checkBoxes->back())
        {
            checkBoxes->back()->isChecked = true;
        }
    }
}

void CheckBoxGroup::set_checked_child(CheckBox *child)
{
    uncheck_all();
    for (auto e : *checkBoxes)
    {
        if (e == child)
            child->isChecked = true;
    }
}