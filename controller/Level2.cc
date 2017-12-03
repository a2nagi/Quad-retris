#include "Level2.h"
#include "IBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "OBlock.h"
#include "JBlock.h"
#include "TBlock.h"
#include "LBlock.h"


using namespace std;

Level2::Level2() {
    setLevel(2);
}

Block* Level2::getNextBlock(){
	Block *b;
    int x = rand()%7;
	switch(x){
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
			b = new TBlock(getLevel());
			break;
		case 4:
			b = new JBlock(getLevel());
			break;
		case 5:
			b = new SBlock(getLevel());
			break;
		case 6:
			b = new ZBlock(getLevel());
			break;
	}
	return b;
}
