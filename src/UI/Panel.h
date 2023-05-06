#ifndef _PANEL_
#define _PANEL_

#include "Clickable/ClickableRect.h"
#include "../DCT/DCTController.h"

class Panel
{
private:
    void set_up_field();
    static int width;
    DCTController *controller;
public:
    ClickableRect *field;

    Panel(DCTController *controller);
    void handle_click(float x, float y);
    void handle_hold(float x1, float y1, float x2, float y2);
    void draw();
};

#endif
