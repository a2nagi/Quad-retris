
#ifndef LEVEL1_H
#define LEVEL1_H

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

class Level1 {
public:
    Block* getNextBlock(char nextBlock = '') override;
};
#endif
