
#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

#include "DCT/DCTController.h"

#include "UI/Panel.h"
#include "Input.h"

int screenWidth = 1000, screenHeight = 500;
int mouseX, mouseY;

DCTController *controller;
Panel *panel;
Input *input;

void render()
{
   panel->draw();
   controller->draw();
}

void keyboard(int key)
{
   input->keyboard_down(key);
}

void keyboardUp(int key)
{
	input->keyboard_up(key);
}

void mouse(int button, int state, int wheel, int direction, int x, int y)
{
	input->att_mouse(button, state, x, y);

	if (wheel != -2)
	{
		input->mouse_wheel(direction);
	}
}

int main(void)
{
   srand(time(nullptr));
   controller = new DCTController();
   controller->DCT_from_rand(10);

   panel = new Panel(controller);
	input = new Input(panel, controller);

   CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
