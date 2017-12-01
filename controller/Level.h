#ifndef LEVEL_H
#define LEVEL_H

class Block;


class Level {
public:
    virtual Block *getNextBlock() = 0;
    virtual ~Level(){};
};
#endif
