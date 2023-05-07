#ifndef _PANEL_
#define _PANEL_

/*o painel da aplicação, controla a posição dos botões e repassa inputs*/

#include "Clickable/ClickableRect.h"
#include "../DCT/DCTController.h"
#include "DCTButtonBar.h"

class Panel
{
private:
    void set_up_field();
    static int width;
    DCTController *controller;
    DCTButtons *buttons;
public:
    ClickableRect *field;
    
    Panel(DCTController *controller);
    void handle_click(float x, float y);
    void handle_hold(float x1, float y1, float x2, float y2);
    void draw();
};

#endif
