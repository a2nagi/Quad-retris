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
    isRandom = true;
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
    counter++;
    return getBlockByChar(c);
}

Block* Level::getBlockByChar(char block) {
    Block *b;
    switch (block) {
        case 'I':
            b = new IBlock(getLevel());
            break;
        case 'J':
            b = new JBlock(getLevel());
            break;
        case 'L':
            b = new LBlock(getLevel());
            break;
        case 'O':
            b = new OBlock(getLevel());
            break;
        case 'S':
            b = new SBlock(getLevel());
            break;
        case 'Z':
            b = new ZBlock(getLevel());
            break;
        case 'T':
            b = new TBlock(getLevel());
            break;
    }
    return b;
}

Level::~Level() {}
