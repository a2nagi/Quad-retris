#include "Level4.h"

using namespace std;

Block* Level4::getNextBlock(char nextBlock = ''){
	int x = rand()%9;
	
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

	else if(x==2 || x==8){
		Block *b= new SBlock();
	}

	else if(x==0 || x==7){
		Block *b= new ZBlock();
	}

	return b;
}