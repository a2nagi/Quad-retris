#include "Level0.h"

using namespace std;


Block* getNextBlock(char nextBlock = ''){
	if(nextBlock=='I'){
		Block *b= new IBlock();
	}

	else if(nextBlock=='S'){
		Block *b= new SBlock();
	}

	else if(nextBlock=='O'){
		Block *b= new OBlock();
	}

	else if(nextBlock=='T'){
		Block *b= new TBlock();
	}

	else if(nextBlock=='Z'){
		Block *b= new ZBlock();
	}

	else if(nextBlock=='J'){
		Block *b= new JBlock();
	}
	else if(nextBlock=='L'){
		Block *b= new LBlock();
	}

	return b;
}
