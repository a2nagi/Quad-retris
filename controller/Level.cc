#include <fstream>
#include "Level.h"
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "TBlock.h"
#include "ZBlock.h"

using namespace std;

Level::Level() {
    counter = 0;
    isRandom = false;
}

void Level::setRandomBlock(bool isRandom) {
    this->isRandom = isRandom;
}

bool Level::getIsRandom() {
    return isRandom;
}

int Level::getLevel() {
    return  level;
}

void Level::setLevel(int level) {
    this->level = level;
}

void Level::readFile(string file) {
    counter = 0;
    ifstream f{file};
    char c;
    while(f>>c){
        allChars.emplace_back(c);
    }
}

Block* Level::getBlockFromFile(){
    if(counter >= allChars.size()) return nullptr;
    char c = allChars.at(counter);
    Block *b;
    switch (c) {
        case 'I':
            b = new IBlock();
            break;
        case 'J':
            b = new JBlock();
            break;
        case 'L':
            b = new LBlock();
            break;
        case 'O':
            b = new OBlock();
        case 'S':
            b = new SBlock();
        case 'Z':
            b = new ZBlock();
        case 'T':
            b = new TBlock();
        }
    counter++;
    return b;
}

virtual ~Level() {}
