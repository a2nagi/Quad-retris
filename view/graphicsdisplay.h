#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "../model/Observer.h"
#include "window.h"

class Grid;
class Info;
class GraphicsDisplay: public Observer{
  Grid* g;
  Xwindow xw;
  void paintBlock(Info I, int rows);
 public:
  GraphicsDisplay(int gridSize, int winSize, Grid *g);
  void notify(Subject &whoNotified) override;
};
#endif
