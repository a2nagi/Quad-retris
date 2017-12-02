#include "Level0.h"

using namespace std;

Level0::Level0() {
	setLevel(0);
}

Block* Level0::getNextBlock(){
    return this->getBlockFromFile();
}
