
#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "gl_canvas2d.h"
#include "DCT/CosineTransformer.h"
#include "Graph/PointSet.h"
#include "Graph/Graph.h"
#include "Basic/Color.h"
#include "Graph/GraphDrawer.h"
#include "Graph/GraphManager.h"
#include "DCTController.h"

int screenWidth = 1000, screenHeight = 500;
int mouseX, mouseY;

DCTController *controller;

void render()
{
   controller->draw();
}

void keyboard(int key)
{
   
}

void keyboardUp(int key)
{
   switch (key)
   {
   case 'a':
      controller->DCT_from_rand(100);
      break;
   case 'b':
      controller->set_quantization_factor(2);
      break;
   }
}

void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   mouseX = x;
   mouseY = y;
}


int main(void)
{
   controller = new DCTController();
   controller->DCT_from_rand(10);

   CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
