
#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "gl_canvas2d.h"
#include "DCT/CosineTransformer.h"
#include "Graph/Graph.h"

Graph *g;

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

void printVec(vector<double> v){
   for(auto i : v){
      cout << "[" << i << "]";
   }
   puts("");
}

int main(void)
{
   vector<double> input = {-5,10,30,20,100,0,9,0};
   vector<double> dct = CosineTransformer::DCT(input);
   vector<double> quant = CosineTransformer::QUANT(dct);
   vector<double> dequant = CosineTransformer::DEQUANT(quant);
   vector<double> idct = CosineTransformer::IDCT(dct);

   printVec(input);
   printVec(dct);
   printVec(quant);
   printVec(dequant);
   printVec(idct);

   g = new Graph(dct);

   CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
