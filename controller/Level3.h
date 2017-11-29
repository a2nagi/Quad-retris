#ifndef LEVEL3_H
#define LEVEL3_H

#include <iostream>
#include <cstdlib>
#include "Block.h"
#include "IBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "OBlock.h"
#include "JBlock.h"
#include "TBlock.h"
#include "OBlock.h"

class Block;

class Level {
public:
   Block *getNextBlock(char nextBlock = '');
};
#endif
