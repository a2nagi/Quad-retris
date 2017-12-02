#ifndef LEVEL4_H
#define LEVEL4_H

#include <cstdlib>
#include "Level.h"

class Block;

class Level4:public Level{
public:
    Block *getNextBlock() override;
    Level4();
};
#endif
