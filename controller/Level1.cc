#include "Level1.h"

using namespace std;

Block* Level1::getNextBlock(char nextBlock = ''){
	int x = rand()%12;
	
	if(x==1 || x==4){
		Block *b= new IBlock();
	}
	else if(x==3 || x==5){
		Block *b= new LBlock();
	}

	else if(x==9 || x==7){
		Block *b= new OBlock();
	}

	else if(x==8 || x==11){
		Block *b= new JBlock();
	}

	else if(x==0 || x==2){
		Block *b= new TBlock();
	}

	else if(x==6){
		Block *b= new SBlock();
	}

	else if(x==10){
		Block *b= new ZBlock();
	}

	return b;
}