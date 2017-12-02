#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include <regex>

class Grid;
class Controller {
    Grid *g;
    TextDisplay *td;
//    std::vector<std::regex *>;
    std::regex *left;
    std::regex *right;
    std::regex *down;
    std::regex *clockwise;
    std::regex *counterclockwise;
    std::regex *drop;
    std::regex *levelup;
    std::regex *leveldown;
    std::regex *norandom;
    std::regex *random;
    std::regex *sequence;
    std::regex *block;
    std::regex *restart;
    std::regex *hint;
public:
    Controller(Grid *g,TextDisplay *td);
    void parseCommand(std::istream* inputstream);
};
#endif
