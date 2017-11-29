#include "Level0.h"

using namespace std;


Block* getNextBlock(char nextBlock = ''){
	Block *b;
	if(nextBlock=='I'){
		b= new IBlock();
	}

	else if(nextBlock=='S'){
		b= new SBlock();
	}

	else if(nextBlock=='O'){
		b= new OBlock();
	}

	else if(nextBlock=='T'){
		b= new TBlock();
	}

	else if(nextBlock=='Z'){
		b= new ZBlock();
	}

	else if(nextBlock=='J'){
		b= new JBlock();
	}
	else if(nextBlock=='L'){
		b= new LBlock();
	}

	return b;
}
