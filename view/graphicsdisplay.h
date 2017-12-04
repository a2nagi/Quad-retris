#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "../model/Observer.h"
#include "window.h"

class Grid;
class GraphicsDisplay: public Observer{
  Grid* g;
  Xwindow xw;
  void paintBlock(Subject &whoNotified);
 public:
  GraphicsDisplay(int gridSize, int winSize, Grid *g);
  void notify(Subject &whoNotified) override;
};
#endif
