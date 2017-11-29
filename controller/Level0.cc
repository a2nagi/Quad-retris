#include "Level0.h"

using namespace std;


Block* getNextBlock(char nextBlock = ''){
	if(nextBlock=='I'){
		Block *b= New IBlock();
	}

	else if(nextBlock=='S'){
		Block *b= New SBlock();
	}

	else if(nextBlock=='O'){
		Block *b= New OBlock();
	}

	else if(nextBlock=='T'){
		Block *b= New TBlock();
	}

	else if(nextBlock=='Z'){
		Block *b= New ZBlock();
	}

	else if(nextBlock=='J'){
		Block *b= New JBlock();
	}
	else if(nextBlock=='L'){
		Block *b= New LBlock();
	}

	return b;
}