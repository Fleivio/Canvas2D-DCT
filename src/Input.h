/*controla o input vindo da main
Possui controladores de estado para saber se o usuário está em hold ou click
é mais genérico do que precisava, não tem seu potancial totalmente utilizado porque o comportamento do painel é bem simples*/

#ifndef _INPUT_
#define _INPUT_

#define LEFT_BUTTON 0
#define RIGHT_BUTTON 2

#define MOUSE_DOWN 0
#define MOUSE_MOVE -2
#define MOUSE_UP 1

#define ANY_MOUSE -2

#define WHEEL_UP 1
#define WHEEL_DOWN -1

#define CTRL_S 19
#define CTRL_D 4
#define DELETE_K 127

#define LEFT_K 200
#define RIGHT_K 202
#define UP_K 201
#define DOWN_K 203

#include "Basic/Vector2.h"
#include "UI/Panel.h"
#include "FileManager/FileHandler.h"
#include "DCT/DCTController.h"
#include <vector>

extern string fName;

enum MouseState
{
    CLICK_DOWN,
    CLICK_UP,
    HOVER,
    HOLD,
    UN_HOLD
};

class Input
{
private:
    MouseState state;
    Vector2 *previousPosition;
    Vector2 *actualPosition;
    Vector2 *movimentDelta;

    Panel *panel;
    DCTController *controller;

    /*recebe uma ação do mouse (move, click etc) e calcula o proximo estado baseado
    no estado atual (se click + move -> hold)*/
    void calc_next_state(int currentAction);
    /*atualiza a direção do movimento do mouse, util para hold*/
    void att_moviment_delta();
    /*chama as funções necessárias dos controladores e do painel, para cada ação desempenhada*/
    void handle_action();

public:
    Input(Panel *panel, DCTController *controller);
    ~Input();

    /*recebe input do mouse (botão clicado, açao, posicao)*/
    void att_mouse(int button, int currentAction, int x, int y);
    /*recebe input do teclado, botão pressionado*/
    void keyboard_down(int key);
    /*recebe input do teclado, botao levantado*/
    void keyboard_up(int key);
    /*recebe input do mouse, wheel*/
    void mouse_wheel(int direction);
};

#endif
