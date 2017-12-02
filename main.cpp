
#include <iostream>
#include "model/Cell.h"
#include "model/Grid.h"
#include "view/TextDisplay.h"
#include "controller/Controller.h"
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

    // 1st Argument=argv[1];
    Grid g;
    g.initGrid();
    TextDisplay *td = g.getTextDisplay();
    Controller c(&g, td);
    c.parseCommand();
}

