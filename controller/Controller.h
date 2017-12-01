#ifndef CONTROLLER_H
#define CONTROLLER_H

class Grid;
class Controller {
    Grid *g;
    TextDisplay *td;
public:
    Controller(Grid *g,TextDisplay *td);
    void parseCommand();
};
#endif
