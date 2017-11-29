#include "Level2.h"

using namespace std;

#include <cstdlib>
#include "Block.h"
#include "IBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "OBlock.h"
#include "JBlock.h"
#include "TBlock.h"
#include "LBlock.h"

class Block;

Block* Level2::getNextBlock(){
	int x = rand()%7;
	Block *b;

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
