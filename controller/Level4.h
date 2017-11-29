#ifndef LEVEL4_H
#define LEVEL4_H

#include <cstdlib>
#include "Block.h"
#include "IBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "OBlock.h"
#include "JBlock.h"
#include "TBlock.h"
#include "LBlock.h"
#include "Level.h"

class Block;

class Level4:public Level{
public:
    Block *getNextBlock() override;
};
#endif
