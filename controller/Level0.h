#ifndef LEVEL0_H
#define LEVEL0_H

#include "Level.h"
class Block;

class Level0: public Level {
public:
	Level0();
    Block* getNextBlock() override;
};
#endif
