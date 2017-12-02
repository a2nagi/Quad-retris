#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include <iostream>
#include <vector>
#include <string>
#include "../model/Observer.h"
#include "../model/State.h"
#include "Window.h"
#include "../model/Info.h"
#include "../model/Grid.h"

class GraphicsDisplay: public Observer{
  Xwindow xw(500,800);
  Grid* g;
 public:
  GraphicsDisplay(Grid *g);
  void notify(Subject &whoNotified) override;
};
#endif
