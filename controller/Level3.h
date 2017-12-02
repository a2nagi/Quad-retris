#ifndef LEVEL3_H
#define LEVEL3_H

#include <iostream>
#include <cstdlib>
#include "Level.h"

class Block;

class Level3: public Level{
public:
   Block *getNextBlock() override;
    Level3();
};
#endif
