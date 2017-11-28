#include <vector>
#include <stdexcept>
#include "Grid.h"
#include "../controller/Block.h"
#include "Cell.h"
#include "../controller/Level.h"
#include "Info.h"

using namespace std;

bool Grid::isCurrentRowFull() {

}

Grid::Grid() {
    rows = 18;
    cols = 11;
    highScore = 0;
    score = 0;
}
void Grid::initGrid() {
    theGrid.clear();

    for( int i = 0; i < rows; i++ ) {
        theGrid.emplace_back(vector<Cell>());
        for( int j = 0 ; j < cols ; j++ ) {
            theGrid.at(i).emplace_back(Cell(i, j));
        }
    }
    highScore = max(highScore, score);
    currentLevel = new Level0();
    levelNumber = 0;
    score = 0;
    currentBlock = currentLevel->getNextBlock();
    changeBlockToGridCoordinates();
    nextBlock = currentLevel->getNextBlock();
}

void Grid::changeBlockToGridCoordinates() {
    int factor = 13;
    if(currentBlock->getCells().at(0)->getInfo().blockType == 'I') {
        factor = 14;
    }
    vector<Cell *> allCells = currentBlock->getCells();
    for(Cell *c: allCells) {
        Info i = c->getInfo();
        i.row+=factor;
        c->setInfo(i);
    }
    if(!copyBlockIntoGrid(currentBlock)) {
        throw gameOver();
    }
}

void Grid::insertNewBlock(Block *block) {
    // if insertion fails it means game over
    vector<Cell * > x = block->getCells();

}


void Grid::updateLevel(int requestedLevel) {
    delete currentLevel;
    switch (requestedLevel) {
        case 0:
            currentLevel = new Level0();
            break;
        case 1:
            currentLevel = new Level1();
            break;
        case 2:
            currentLevel = new Level2();
            break;
        case 3:
            currentLevel = new Level3();
            break;
    }
}

void Grid::dropBlock() {
    
}

void Grid::moveCurrentBlockDown() {

}

void Grid::nextLevel() {
    if( this->levelNumber == 3 ) {
        return;
    }
    this->levelNumber++;
    updateLevel(this->levelNumber);
}

void Grid::levelDown() {
    if( this->levelNumber == 0 ) {
        return;
    }
    this->levelNumber--;
    updateLevel(this->levelNumber);
}

int Grid::getLevel() {
    return this->levelNumber;
}

int Grid::getScore() {
    return this->score;
}

int Grid::getHighScore() {
    return this->highScore;
}

bool Grid::copyBlockIntoGrid(Block *block) {
    vector<Cell*> blocks = block->getCells();
    for(Cell *c: blocks) {
        int row = c->getInfo().row;
        int col = c->getInfo().col;
        if(theGrid.at(row).at(col).getInfo().blockType != ' ') {
            // cannot move block
            return false;
        }
    }
    for(Cell *c: blocks) {
        int row = c->getInfo().row;
        int col = c->getInfo().col;
        theGrid.at(row).at(col).setPiece(c->getInfo().blockType);
    }

    for(Cell *c: currentBlock->getCells()) {
        int row = c->getInfo().row;
        int col = c->getInfo().col;
        theGrid.at(row).at(col).setPiece(' ');
    }
    return true;
}

void Grid::moveCurrentBlockLeftRight(Direction d) {
    vector<Cell*> blocks = currentBlock->getCells();
    Block currentBlockCopy = *currentBlock;
    try {
        currentBlockCopy.move(d);
        copyBlockIntoGrid(&currentBlockCopy);
    }
    catch (out_of_range&) {
        return;
    }
    *currentBlock = currentBlockCopy;
}

void Grid::rotateBlock(Rotate r) {
    vector<Cell*> blocks = currentBlock->getCells();
    Block currentBlockCopy = *currentBlock;
    try {
        currentBlockCopy.rotate(r);
        copyBlockIntoGrid(&currentBlockCopy);
    }
    catch (out_of_range&) {
        return;
    }
    *currentBlock = currentBlockCopy;
}

Block* Grid::getCurrentBlock() {
    return currentBlock;
}

Block * Grid::getNextBlock() {
    return nextBlock;
}
