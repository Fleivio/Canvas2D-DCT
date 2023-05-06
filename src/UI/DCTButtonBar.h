#ifndef DCT_BUTTON_BAR
#define DCT_BUTTON_BAR

#include "UiElements/Bar.h"
#include "UiElements/Button.h"
#include "UiElements/Slider.h"
#include "../Drawer/Drawer.h"
#include "../DCT/DCTController.h"
#include "Clickable/ClickableRect.h"

class DCTButtons : public Bar{
    private:
        Button *randomizeButton;
        Button *loadButton;
        Button *saveButton;
        Slider *quantSlider;

        DCTController *controller;

        static float quantSliderDelta;
    public:
        DCTButtons(float x1, float y1, float x2, float y2, DCTController *controller);

        void draw() override;
        void on_click(float x, float y) override;
        void set_up_childs(float x1, float y1, float x2, float y2) override;

        void on_hold(float x, float y);

};

#endif