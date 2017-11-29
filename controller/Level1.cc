#include "Level1.h"

using namespace std;

Block* Level1::getNextBlock(){
	int x = rand()%12;
	
	Block *b;

	if(x==1 || x==4){
		b= new IBlock();
	}
	else if(x==3 || x==5){
		b= new LBlock();
	}

	else if(x==9 || x==7){
		b= new OBlock();
	}

	else if(x==8 || x==11){
		b= new JBlock();
	}

	else if(x==0 || x==2){
		b= new TBlock();
	}

	else if(x==6){
		b= new SBlock();
	}

	else if(x==10){
		b= new ZBlock();
	}

	return b;
}
