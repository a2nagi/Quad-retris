#ifndef CONTROLLER_H
#define CONTROLLER_H

class Grid;
class Controller {
    Grid *g;
public:
    Controller(Grid *g);
    void parseCommand();
};
#endif
