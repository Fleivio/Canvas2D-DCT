#include "DCTButtonBar.h"

float DCTButtons::quantSliderDelta = 50;

DCTButtons::DCTButtons(float x1, float y1, float x2, float y2, DCTController *controller) : Bar(x1, y1, x2, y2){
    this->controller = controller;
    set_up_childs(x1, y1, x2, y2);
}

void DCTButtons::draw(){
    Drawer::draw(field);
    Drawer::draw(loadButton);
    Drawer::draw(randomizeButton);
    Drawer::draw(saveButton);
    Drawer::draw(quantSlider);
}

void DCTButtons::on_click(float x, float y){
    if(!field->is_point_inside(x,y)) return;

    if(loadButton->verify_on_click(x,y)) return;
    else if(saveButton->verify_on_click(x,y)) return;
    else if(randomizeButton->verify_on_click(x,y)) return;
    else if(quantSlider->field->is_point_inside(x,y)) {
        quantSlider->on_click(x,y);
    }
}

void DCTButtons::on_hold(float x, float y){
    if(!field->is_point_inside(x,y)) return;

    if(quantSlider->field->is_point_inside(x,y)) {
        quantSlider->on_click(x,y);
    }
}

void DCTButtons::set_up_childs(float x1, float y1, float x2, float y2){
    float buttonW = x2 - x1;
    float buttonH = (y2 - y1) / 4;

    loadButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + defaultGap,
                                   x1 + defaultGap + buttonW,
                                   y1 + defaultGap + buttonH), "Load");
    loadButton->add_callback([this](){this->controller->DCT_from_file();});

    saveButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH),
                                   x1 + defaultGap + buttonW,
                                   y1 + (defaultGap + buttonH) + buttonH), "Save");
    saveButton->add_callback([this](){this->controller->save_output();});

    randomizeButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH) * 2,
                                   x1 + defaultGap + buttonW,
                                   y1 + (defaultGap + buttonH) * 2 + buttonH), "Random");
    randomizeButton->add_callback([this](){this->controller->DCT_from_rand(100);});

    quantSlider = new Slider(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH) * 3,
                                   x1 + defaultGap + buttonW,
                                   y1 + (defaultGap + buttonH) * 3 + buttonH);
    quantSlider->set_value(controller->get_quantization_factor() * quantSliderDelta);
    quantSlider->add_callback([this](){this->controller->set_quantization_factor(
        this->quantSlider->calc_value() / this->quantSliderDelta
    );});

}
