#include "Level1.h"

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
            b = new IBlock();
            break;
        case 2:
        case 3:
            b = new LBlock();
            break;
        case 4:
        case 5:
            b = new OBlock();
            break;
        case 6:
        case 7:
            b = new TBlock();
            break;
        case 8:
        case 9:
            b = new JBlock();
            break;
        case 10:
            b = new SBlock();
            break;
        case 11:
            b = new ZBlock();
            break;
    }

	return b;
}
