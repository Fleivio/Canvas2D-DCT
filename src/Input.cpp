#include "Input.h"

Input::Input(Panel *panel, DCTController *controller)
{
    this->panel = panel;
    this->controller = controller;
    this->previousPosition = new Vector2(0, 0);
    this->actualPosition = new Vector2(0, 0);
    this->movimentDelta = new Vector2(0, 0);
    this->state = HOVER;
}

Input::~Input()
{
    delete previousPosition;
    delete actualPosition;
    delete movimentDelta;
}

void Input::att_mouse(int button, int currentAction, int x, int y)
{
    if (button == RIGHT_BUTTON)
    {
        return;
    }

    previousPosition->set(*actualPosition);
    actualPosition->set(x, y);

    calc_next_state(currentAction);
    handle_action();
}

void Input::calc_next_state(int currentAction)
{
    switch (currentAction)
    {
    case MOUSE_DOWN:
        if (state == HOVER || state == CLICK_UP || state == UN_HOLD)
        {
            state = CLICK_DOWN;
        }
        break;
    case MOUSE_MOVE:
        if (state == CLICK_DOWN)
        {
            state = HOLD;
        }
        else if (state == UN_HOLD || state == CLICK_UP)
        {
            state = HOVER;
        }
        break;
    case MOUSE_UP:
        if (state == HOLD)
        {
            state = UN_HOLD;
        }
        else if (state == CLICK_DOWN)
        {
            state = CLICK_UP;
        }
        break;
    }
}

void Input::handle_action()
{
    switch (state)
    {
    case CLICK_DOWN:
        panel->handle_click(actualPosition->x, actualPosition->y);
        break;
    case CLICK_UP:
        // não precisei
        break;
    case HOVER:
        // não precisei
        break;
    case HOLD:
        panel->handle_hold(previousPosition->x, previousPosition->y, actualPosition->x, actualPosition->y);
        break;
    case UN_HOLD:
        // não precisei
        break;
    }
}

void Input::att_moviment_delta()
{
    movimentDelta->x = actualPosition->x - previousPosition->x;
    movimentDelta->y = actualPosition->y - previousPosition->y;
}

void Input::keyboard_down(int key)
{
    if(key == 'r') controller->DCT_from_rand(10);
    return;
    // switch (key)
    // {
    // case CTRL_S:

    // default:

    // }
}

void Input::keyboard_up(int key)
{
    return;
    // switch (key)
    // {
    // case DELETE_K:

    // case CTRL_D:

    // }
}

void Input::mouse_wheel(int direction)
{   
    return;
    // if (direction == WHEEL_UP)

    // else if (direction == WHEEL_DOWN)

}