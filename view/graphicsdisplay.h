#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "../model/Observer.h"
#include "window.h"

class Block;
class Grid;
class Info;
class GraphicsDisplay: public Observer{
  Grid* g;
  Xwindow xw;
  Block *b;
  void paintBlock(Info I, int rows);
 public:
  GraphicsDisplay(int gridSize, int winSize, Grid *g);
  void notify(Subject &whoNotified) override;
};
#endif
