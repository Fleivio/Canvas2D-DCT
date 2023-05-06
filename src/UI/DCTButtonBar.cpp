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
        ((Button*)quantSlider)->on_click();
    }
}

void DCTButtons::on_hold(float x, float y){
    if(!field->is_point_inside(x,y)) return;

    if(quantSlider->field->is_point_inside(x,y)) {
        quantSlider->on_click(x,y);
        ((Button*)quantSlider)->on_click();
    }
}

void DCTButtons::set_up_childs(float x1, float y1, float x2, float y2){
    float buttonW = x2 - x1;
    float buttonH = (y2 - y1 - (defaultGap * 5)) / 4;

    loadButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + defaultGap + buttonH), "Load");
    loadButton->add_callback([this](){this->controller->DCT_from_file();});
    loadButton->field->set_color(0,1,0);

    saveButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH) + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + (defaultGap*2 + buttonH) + buttonH), "Save");
    saveButton->add_callback([this](){this->controller->save_output();});
    saveButton->field->set_color(0,1,0);

    randomizeButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH) * 2 + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + (defaultGap + buttonH) * 2 + buttonH + defaultGap), "Random");
    randomizeButton->add_callback([this](){this->controller->DCT_from_rand(500);});
    randomizeButton->field->set_color(1,0.2,0.5);

    quantSlider = new Slider(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH) * 3 + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + (defaultGap + buttonH) * 3 + buttonH/2 + defaultGap);
    quantSlider->add_callback([this](){this->controller->set_quantization_factor(
        (float) this->quantSlider->calc_value() / this->quantSliderDelta
    );});
    quantSlider->field->set_color(1,1,0.8);

}
