#ifndef LEVEL0_H
#define LEVEL0_H

#include "Level.h"
#include "Block.h"
#include "IBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "OBlock.h"
#include "JBlock.h"
#include "TBlock.h"
#include "LBlock.h"
#include <fstream>
#include <vector>


#include "Block.h"
#include "IBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "OBlock.h"
#include "JBlock.h"
#include "TBlock.h"
#include "OBlock.h"

class Block;

class Level0: public Level {
	std::string filename;
	std::vector <char> seq;
	std::ifstream *f;
public:
	Level0(std::string filename);
    Block* getNextBlock() override;
	~Level0();
};
#endif
