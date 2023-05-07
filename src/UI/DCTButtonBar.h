#ifndef DCT_BUTTON_BAR
#define DCT_BUTTON_BAR

/*barra de controle para os gráficos, controla todos os botões desta aplicação*/

#include <iomanip>
using namespace std;

#include "UiElements/Bar.h"
#include "UiElements/Button.h"
#include "UiElements/Slider.h"
#include "UiElements/CheckBox.h"
#include "../Drawer/Drawer.h"
#include "../DCT/DCTController.h"
#include "Clickable/ClickableRect.h"

class DCTButtons : public Bar{
    private:
        Button *randomizeButton;
        Button *loadButton;
        Button *reloadButton;
        Button *saveButton;
        Button *sinizeButton;
        Slider *quantSlider;
        Slider *nSlider;
        CheckBox *showPoints;

        DCTController *controller;

        static float quantSliderDelta;
        int get_input_size();
    public:
        //construtor, recebe veritices e ponteiro para o controlador
        DCTButtons(float x1, float y1, float x2, float y2, DCTController *controller);

        void draw() override;
        void on_click(float x, float y) override;
        void set_up_childs(float x1, float y1, float x2, float y2) override;
        void on_hold(float x, float y);

};

#endif