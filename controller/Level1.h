
#ifndef LEVEL1_H
#define LEVEL1_H

#include <cstdlib>
#include "Level.h"

class Block;

class Level1:public Level{
public:
    Block* getNextBlock() override;
    Level1();
};
#endif
