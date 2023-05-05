
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

int screenWidth = 500, screenHeight = 500;
int mouseX, mouseY;

GraphManager *gm;

void render()
{
   gm->draw();
}

void keyboard(int key)
{

}

void keyboardUp(int key)
{

}

void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   mouseX = x;
   mouseY = y;
}


int main(void)
{
   gm = DCTController::init_graphs();

   CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
