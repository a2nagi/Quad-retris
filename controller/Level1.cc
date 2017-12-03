#include "Level1.h"
#include "Block.h"
#include "IBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "OBlock.h"
#include "JBlock.h"
#include "TBlock.h"
#include "LBlock.h"

using namespace std;

Level1::Level1() {
    setLevel(1);
}

Block* Level1::getNextBlock(){

	int x = rand()%12;
	
	Block *b;
	switch(x) {
        case 0:
        case 1:
            b = new IBlock(getLevel());
            break;
        case 2:
        case 3:
            b = new LBlock(getLevel());
            break;
        case 4:
        case 5:
            b = new OBlock(getLevel());
            break;
        case 6:
        case 7:
            b = new TBlock(getLevel());
            break;
        case 8:
        case 9:
            b = new JBlock(getLevel());
            break;
        case 10:
            b = new SBlock(getLevel());
            break;
        case 11:
            b = new ZBlock(getLevel());
            break;
    }

	return b;
}
