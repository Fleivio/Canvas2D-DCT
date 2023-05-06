#include "CheckBox.h"

CheckBox::CheckBox(ClickableField *field, string label) : Button(field, label)
{
    isChecked = false;
    add_callback([this]()
                 { isChecked = !isChecked; });
    selectedColor = field->color->copy();
    unSelectedColor = field->color->copy();
}

CheckBox::CheckBox(ClickableField *field, string label, Color *selectionColor) : Button(field, label)
{
    isChecked = false;
    this->selectedColor = selectionColor->copy();
    unSelectedColor = field->color->copy();
    add_callback([this]()
                 { isChecked = !isChecked; });
}

void CheckBox::set_checked(bool isChecked)
{
    this->isChecked = isChecked;
}

CheckBox::~CheckBox()
{
    delete selectedColor;
    delete unSelectedColor;
}

void CheckBox::set_selected_color(Color *color)
{
    delete selectedColor;
    selectedColor = color->copy();
}

void CheckBox::set_unselected_color(Color *color)
{
    delete unSelectedColor;
    unSelectedColor = color->copy();
}