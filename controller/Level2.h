#ifndef LEVEL2_H
#define LEVEL2_H

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

class Level2:public Level{
public:
	Block* getNextBlock() override;
	Level2();
};

#endif
