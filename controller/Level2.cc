#include "Level2.h"

using namespace std;

Level2::Level2() {
    setLevel(2);
}

Block* Level2::getNextBlock(){
	Block *b;
	int x = rand()%7;
	if(x==1){
		b= new IBlock();
	}
	else if(x==3){
		b= new LBlock();
	}

	else if(x==4){
		b= new OBlock();
	}

	else if(x==5){
		b= new JBlock();
	}

	else if(x==6){
		b= new TBlock();
	}

	else if(x==2){
		b= new SBlock();
	}

	else if(x==0){
		b= new ZBlock();
	}

	return b;
}
