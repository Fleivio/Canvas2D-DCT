
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

Graph *gorig;
Graph *gdct;
Graph *gquantiz;
Graph *gdequant;
Graph *gidct;
Graph *gdiff;

int screenWidth = 500, screenHeight = 500;
int mouseX, mouseY;

void render()
{
   GraphDrawer::draw(gorig);
   // GraphDrawer::draw(gdct);
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
   vector<double> input = {-5,10,30,20,100,0,9,0, 19, 30, 40 , 5, 8 ,90, 37, 80};
   vector<double> dct = CosineTransformer::DCT(input);
   vector<double> quant = CosineTransformer::QUANT(dct);
   vector<double> dequant = CosineTransformer::DEQUANT(quant);
   vector<double> idct = CosineTransformer::IDCT(dct);
   vector<double> dif;

   for(unsigned int i = 0; i < input.size(); i++){
      dif.push_back(input.at(i) - idct.at(i));
   }

   PointSet *sInput = new PointSet(input);
   PointSet *sDct = new PointSet(dct);
   PointSet *sQuant = new PointSet(quant);
   PointSet *sDequant = new PointSet(dequant);
   PointSet *sIdct = new PointSet(idct);
   PointSet *sDiff = new PointSet(dif);

   gorig = new Graph("original", new Vector2(20, 30), new Vector2(200, 200), new Color(0,0,0), new Color(1,0,0), sInput);
   gdct = new Graph("DCT", new Vector2(10, 200), new Vector2(200, 400), new Color(0,0,0), new Color(1,0,0), sDct);
   // gquantiz =
   // gdequant =
   // gidct =
   // gdiff =

   CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
