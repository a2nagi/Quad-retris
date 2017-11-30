#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <regex>
// #include <ctype>
#include <sstream>
#include <string>
#include <fstream>
#include "Block.h"
#include "Level.h"
#include "../model/Grid.h"


class Controller {
    Grid *g;
public:
    Controller(Grid *g);
    void parseCommand();
};
#endif
