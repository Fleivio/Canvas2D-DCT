
#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "gl_canvas2d.h"
#include "DCT/CosineTransformer.h"

int screenWidth = 500, screenHeight = 500;
int mouseX, mouseY;

void render()
{

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
   vector<double> input = {1,2,3,4,5,6,7,8};
   vector<double> dct = CosineTransformer::DCT(input);
   vector<double> idct = CosineTransformer::IDCT(dct);

   for(auto i : input){
      cout << "[" << i << "]";
   }
   puts("");

   for(auto i : dct){
      cout << "[" << i << "]";
   }
   puts("");

   for(auto i : idct){
      cout << "[" << i << "]";
   }
   puts("");


   CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
