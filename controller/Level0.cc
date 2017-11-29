#include "Level0.h"

using namespace std;

Level0::Level0(string filename): filename{filename}{
	f= new ifstream(filename);
	char c;
	vector <char> seq;
	while(*f>>c){
		seq.emplace_back(c);
	}

}


Block* Level0::getNextBlock(){
	if(seq.size()==0){
		return nullptr;
	}
	Block *b;

    int currChar=seq.at(0);

    if(currChar=='I'){
		b= new IBlock();
	}

	else if(currChar=='S'){
		b= new SBlock();
	}

	else if(currChar=='O'){
		b= new OBlock();
	}

	else if(currChar=='T'){
		b= new TBlock();
	}

	else if(currChar=='Z'){
		b= new ZBlock();
	}

	else if(currChar=='J'){
		b= new JBlock();
	}
	else if(currChar=='L'){
		b= new LBlock();
	}

    seq.erase(seq.begin());

	return b;
}

Level0::~Level0(){
	delete f;
}
