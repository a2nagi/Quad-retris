#include "Level4.h"

using namespace std;

Level4::Level4() {
    setLevel(4);
}

Block* Level4::getNextBlock() {
    if(this->getIsRandom()) {
        return this->getBlockFromFile();
    }
	int x = rand()%9;
	Block *b;

	switch(x) {
		case 0:
			b = new IBlock();
			break;
		case 1:
			b = new LBlock();
			break;
		case 2:
			b = new OBlock();
			break;
		case 3:
			b = new JBlock();
			break;
		case 4:
			b = new TBlock();
			break;
		case 5:
		case 6:
			b = new SBlock();
			break;
		case 7:
		case 8:
			b = new ZBlock();
			break;
	}
	return b;
}
