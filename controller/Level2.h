#ifndef LEVEL2_H
#define LEVEL2_H

#include <cstdlib>
#include "Level.h"

class Block;

class Level2:public Level{
public:
	Block* getNextBlock() override;
	Level2();
};

#endif
