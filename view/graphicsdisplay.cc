#include <iostream>
#include "graphicsdisplay.h"
#include "../model/Info.h"
#include "../model/Subject.h"
#include "../model/Grid.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(int gridSize, int winSize, Grid *g): g{g}, xw{gridSize, winSize}  {

  xw.drawString(200, 20, "Project Quadris", Xwindow::Blue);
  xw.fillRectangle(0,100,500,500,Xwindow::Cyan);
}
void GraphicsDisplay::paintBlock(Subject &whoNotified) {
  int rows = 17;
  Info I = whoNotified.getInfo();
  int cellColSize = 500 / 11;
  int cellRowSize = 500 / 18;
  switch(I.blockType) {
   case 'I':
      xw.fillRectangle(I.col*cellColSize,150+(rows - I.row)*cellRowSize,cellColSize,cellRowSize, Xwindow::Green);
      break;
   case 'J':
      xw.fillRectangle(I.col*cellColSize,150+(rows - I.row)*cellRowSize,cellColSize,cellRowSize, Xwindow::Black);
      break;
   case 'L':
      xw.fillRectangle(I.col*cellColSize,150+(rows-I.row)*cellRowSize,cellColSize,cellRowSize, Xwindow::Blue);
      break;
   case 'O':
      xw.fillRectangle(I.col*cellColSize,150+(rows-I.row)*cellRowSize,cellColSize,cellRowSize, Xwindow::Brown);
      break;
   case 'S':
      xw.fillRectangle(I.col*cellColSize,150+(rows-I.row)*cellRowSize,cellColSize,cellRowSize, Xwindow::Yellow);
      break;
   case 'Z':
      xw.fillRectangle(I.col*cellColSize,150+(rows - I.row)*cellRowSize,cellColSize,cellRowSize, Xwindow::Magenta);
      break;
   case 'T':
      xw.fillRectangle(I.col*cellColSize,150+(rows - I.row)*cellRowSize,cellColSize,cellRowSize, Xwindow::Orange);
       break;
     default:
      xw.fillRectangle(I.col*cellColSize,150+(rows - I.row) *cellRowSize,cellColSize,cellRowSize, Xwindow::Cyan);
  }
}

void GraphicsDisplay::notify(Subject &whoNotified) {
  xw.fillRectangle(80,30,500,70, Xwindow::White);
  xw.drawString(100, 40, "Level: " + to_string(g->getLevel()), Xwindow::Blue);
  xw.drawString(100, 60, "Score: " + to_string(g->getScore()), Xwindow::Blue);
  xw.drawString(100, 80, "Hi Score " + to_string(g->getHighScore()), Xwindow::Blue);
  paintBlock(whoNotified);
}
