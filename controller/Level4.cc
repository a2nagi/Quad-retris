#include "Level4.h"
#include "Block.h"
#include "IBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "OBlock.h"
#include "JBlock.h"
#include "TBlock.h"
#include "LBlock.h"

using namespace std;

Level4::Level4() {
    setLevel(4);
}

Block* Level4::getNextBlock() {
    if(!this->getIsRandom()) {
        return this->getBlockFromFile();
    }
	int x = rand()%9;
	Block *b;

	switch(x) {
		case 0:
			b = new IBlock(getLevel());
			break;
		case 1:
			b = new LBlock(getLevel());
			break;
		case 2:
			b = new OBlock(getLevel());
			break;
		case 3:
			b = new JBlock(getLevel());
			break;
		case 4:
			b = new TBlock(getLevel());
			break;
		case 5:
		case 6:
			b = new SBlock(getLevel());
			break;
		case 7:
		case 8:
			b = new ZBlock(getLevel());
			break;
	}
	return b;
}
