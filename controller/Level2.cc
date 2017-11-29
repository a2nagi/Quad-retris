#include "Level2.h"

using namespace std;

Block* Level2::getNextBlock(char nextBlock = ''){
	int x = rand()%7;
	
	if(x==1){
		Block *b= new IBlock();
	}
	else if(x==3){
		Block *b= new LBlock();
	}

	else if(x==4){
		Block *b= new OBlock();
	}

	else if(x==5){
		Block *b= new JBlock();
	}

	else if(x==6){
		Block *b= new TBlock();
	}

	else if(x==2){
		Block *b= new SBlock();
	}

	else if(x==0){
		Block *b= new ZBlock();
	}

	return b;
}