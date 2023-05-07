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
    Drawer::draw(reloadButton);
    Drawer::draw(sinizeButton);
    Drawer::draw(nSlider);
    Drawer::draw(showPoints);
}

void DCTButtons::on_click(float x, float y){
    if(!field->is_point_inside(x,y)) return;

    if(loadButton->verify_on_click(x,y)) return;
    else if(saveButton->verify_on_click(x,y)) return;
    else if(randomizeButton->verify_on_click(x,y)) return;
    else if(reloadButton->verify_on_click(x,y)) return;
    else if(sinizeButton->verify_on_click(x,y)) return;
    else if(showPoints->verify_on_click(x,y)) return;
    else if(quantSlider->field->is_point_inside(x,y)) {
        quantSlider->on_click(x,y);
        ((Button*)quantSlider)->on_click();
    }
    else if(nSlider->field->is_point_inside(x,y)) {
        nSlider->on_click(x,y);
        ((Button*)nSlider)->on_click();
    }
}

void DCTButtons::on_hold(float x, float y){
    if(!field->is_point_inside(x,y)) return;

    if(quantSlider->field->is_point_inside(x,y)) {
        quantSlider->on_click(x,y);
        ((Button*)quantSlider)->on_click();
    }else if(nSlider->field->is_point_inside(x,y)) {
        nSlider->on_click(x,y);
        ((Button*)nSlider)->on_click();
        cout << nSlider->calc_value();
    }
}

void DCTButtons::set_up_childs(float x1, float y1, float x2, float y2){
    int n = 8;
    float buttonW = x2 - x1;
    float buttonH = (y2 - y1 - (defaultGap * (n+1))) / n;
    float sliderH = 10;

    loadButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + defaultGap + buttonH), "Load");
    loadButton->add_callback([this](){this->controller->DCT_from_file();});
    loadButton->field->set_color(0,1,0);

    saveButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH) + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + (defaultGap*2 + buttonH) + buttonH), "Save from input");
    saveButton->add_callback([this](){this->controller->save_output();});
    saveButton->field->set_color(0,1,0);

    reloadButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH)*2 + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + (defaultGap + buttonH)*2 + buttonH), "Save as input");
    reloadButton->add_callback([this](){this->controller->load_from_actual();});
    reloadButton->field->set_color(0,1,0);

    quantSlider = new Slider(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH) * 3 + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + (defaultGap + buttonH) * 3 + sliderH + defaultGap);
    quantSlider->add_callback([this](){this->controller->set_quantization_factor(
        (float) this->quantSlider->calc_value() / this->quantSliderDelta
    );});
    quantSlider->add_callback([this](){
        string out = "fator: ";
        out += to_string((float)this->controller->get_quantization_factor());
        out.erase(out.length() - 4, 4);
        this->quantSlider->set_label(out);
    });
    quantSlider->set_label("fator: 0.1");
    quantSlider->field->set_color(1,1,0.8);
    quantSlider->actual->set_color(1, 0.5, 0.5);

    randomizeButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH) * 4 + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + (defaultGap + buttonH) * 4 + buttonH + defaultGap), "Random");
    randomizeButton->add_callback([this](){this->controller->DCT_from_rand( this->get_input_size() );});
    randomizeButton->field->set_color(1,0.2,0.5);

    sinizeButton = new Button( new ClickableRect(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH) * 5 + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + (defaultGap + buttonH) * 5 + buttonH + defaultGap), "Sine");
    sinizeButton->add_callback([this](){this->controller->DCT_from_sin( this->get_input_size() );});
    sinizeButton->field->set_color(1, 0.2, 0.5);

    nSlider = new Slider(x1 + defaultGap,
                            y1 + (defaultGap + buttonH) * 6 + defaultGap,
                            x1 - defaultGap + buttonW,
                            y1 + (defaultGap + buttonH) * 6 + sliderH + defaultGap);
    nSlider->field->set_color(1, 1, 0.8);
    nSlider->actual->set_color(1, 0.5, 0.5);

    showPoints = new CheckBox(new ClickableRect(x1 + defaultGap,
                                   y1 + (defaultGap + buttonH) * 7 + defaultGap,
                                   x1 - defaultGap + buttonW,
                                   y1 + (defaultGap + buttonH) * 7 + buttonH + defaultGap), "Show Points");
    showPoints->set_selected_color(0,1,0);
    showPoints->set_unselected_color(0.6,0.6,0.6);
    showPoints->isChecked = false;
    showPoints->add_callback(
        [](){
            GraphDrawer::showPoints = ! GraphDrawer::showPoints;
        }
    );
}

int DCTButtons::get_input_size(){
    int a = (5.12 - 0.32) * nSlider->calc_value() + 32;
    return a;
}
