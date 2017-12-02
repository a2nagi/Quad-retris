#include <vector>
#include <stdexcept>
#include "Grid.h"
#include "../controller/Block.h"
#include "Cell.h"
#include "../controller/Level0.h"
#include "../controller/Level1.h"
#include "../controller/Level2.h"
#include "../controller/Level3.h"
#include "../controller/Level4.h"
#include "../view/TextDisplay.h"

using namespace std;

bool Grid::isCurrentRowFull(int row) {
    bool isFull = true;
    for( int i = 0; i < cols; i++) {
        if(theGrid.at(row).at(i).getInfo().blockType == ' ') {
            isFull = false;
            break;
        }
    }
    return isFull;
}

Grid::Grid() {
    rows = 18;
    cols = 11;
    highScore = 0;
    score = 0;
}

int Grid::getRows() {
    return rows;
}

int Grid::getColumns() {
    return cols;
}

void Grid::makeCurrentLevelRandom() {
    if(levelNumber < 3 ) return;
    currentLevel->setRandomBlock(true);
}

void Grid::clearGrid() {

}

void Grid::makeCurrentLevelFromFile(std::string fileName) {
    if(levelNumber < 3) return;
    currentLevel->readFile(fileName);
    currentLevel->setRandomBlock(false);
}

void Grid::initGrid(string fileName, int initialLevel, bool isTextOnly) {
    allLevels.emplace_back(new Level0());
    allLevels.emplace_back(new Level1());
    allLevels.emplace_back(new Level2());
    allLevels.emplace_back(new Level3());
    allLevels.emplace_back(new Level4());
    allLevels.at(0)->readFile(fileName);
    theGrid.clear();
    td = new TextDisplay(this);
    if(!isTextOnly) {
        throw "To DO";
    }
    for( int i = 0; i < rows; i++ ) {
        theGrid.emplace_back(vector<Cell>());
        for( int j = 0 ; j < cols ; j++ ) {
            theGrid.at(i).emplace_back(Cell(i, j));
            theGrid.at(i).at(j).attach(td);
        }
    }
    highScore = max(highScore, score);
    currentLevel = allLevels.at(initialLevel);
    levelNumber = 0;
    score = 0;
    currentBlock = currentLevel->getNextBlock();
    changeBlockToGridCoordinates();
    copyBlockIntoGrid(currentBlock);
    nextBlock = currentLevel->getNextBlock();
}

void Grid::moveToNextBlock() {
    currentBlock = nextBlock;
    changeBlockToGridCoordinates();
    copyBlockIntoGrid(currentBlock);
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

Grid::~Grid() {
    for(unsigned int i = 0; i < allLevels.size(); i++) {
        delete allLevels.at(i);
    }
}

void Grid::updateLevel(int requestedLevel) {
    switch (requestedLevel) {
        case 0:
            currentLevel = allLevels.at(0);
            break;
        case 1:
            currentLevel = allLevels.at(1);
            break;
        case 2:
            currentLevel = allLevels.at(2);
            break;
        case 3:
            currentLevel = allLevels.at(3);
            break;
        case 4:
            currentLevel = allLevels.at(4);
            break;
    }
}

void Grid::showHint() {
    //ToDo
}

void Grid::eraseRow(int row) {
    if(row == 15) return;
    for( int i = 0; i < cols; i++ ) {
        theGrid.at(row).at(i) = theGrid.at(row+1).at(i);
    }
    eraseRow(row+1);
}

void Grid::dropBlock() {
    moveCurrentBlockDown(18);
}

void Grid::emptyCellsInGrid(vector<Cell *> cells) {
    for(unsigned int i = 0; i < cells.size(); i++) {
        int row = cells.at(i)->getInfo().row;
        int col = cells.at(i)->getInfo().col;
        theGrid.at(row).at(col).setPiece(' ');
    }
}

bool Grid::moveCurrentBlockDown(int times) {
    bool canMove = false;
    for(int i = 0; i < times; i++) {
        vector<Cell*> blocks = currentBlock->getCells();
        vector<Cell *> cellCopy = currentBlock->copyCells();
        currentBlock->move(Direction::down);
        emptyCellsInGrid(cellCopy);
        bool canMove = copyBlockIntoGrid(currentBlock);
        if(canMove) {
            vector<Cell *> cells = currentBlock->getCells();
            for(Cell *c: cells) {
                if(c->getInfo().row >= 15 ) {
                    throw gameOver();
                }
            }
            bool moveNext = false;
            for(Cell *c: blocks) {
                if(isCurrentRowFull(c->getInfo().row)) {
                    eraseRow(c->getInfo().row);
                    moveNext = true;
                }
            }
            if(!moveNext) {
                vector<Cell *> minRowCells = currentBlock->getMinRows();
                for(Cell *c: minRowCells) {
                    int row = c->getInfo().row;
                    int col = c->getInfo().col;
                    if ( row == 0 || theGrid.at(row-1).at(col).getInfo().blockType != ' ' ) {
                        moveNext = true;
                        break;
                    }
                }
            }
            if(moveNext) {
                moveToNextBlock();
                break;
            }
        }
        else {
            break;
        }
    }

    return canMove;

}

TextDisplay* Grid::getTextDisplay() {
    return td;
}

void Grid::nextLevel(int counter) {
    if( this->levelNumber+counter > 4 ) {
        return;
    }
    this->levelNumber+=counter;
    updateLevel(this->levelNumber);
}

void Grid::levelDown(int counter) {
    if( this->levelNumber-counter < 0 ) {
        return;
    }
    this->levelNumber-=counter;
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

    return true;
}

void Grid::moveCurrentBlockLeftRight(Direction d, int times) {
    for(int i = 0 ; i < times; i++) {
        vector<Cell*> blocks = currentBlock->getCells();
        vector<Cell *> cellCopy = currentBlock->copyCells();
        currentBlock->move(d);
        for(Cell *c : blocks){
            unsigned int row = c->getInfo().row;
            unsigned int col = c->getInfo().col;
            if(col >= theGrid.at(0).size() || row >= theGrid.size()) {
                if(d == Direction::right) {
                    currentBlock->move(Direction::left);
                }
                else {
                    currentBlock->move(Direction::right);
                }
                break;
            }
        }
        emptyCellsInGrid(cellCopy);
        copyBlockIntoGrid(currentBlock);
    }
}

void Grid::replaceCurrentBlock(char block) {
    delete currentBlock;
    currentBlock = currentLevel->getBlockByChar(block);
}

void Grid::rotateBlock(int multiple) {
    for(int i = 0 ; i < multiple; i++) {
        vector<Cell*> blocks = currentBlock->getCells();
        vector<Cell*> cellCopy = currentBlock->copyCells();
        currentBlock->rotate();
        for(Cell *c : blocks){
            unsigned int row = c->getInfo().row;
            unsigned int col = c->getInfo().col;
            if(col >= theGrid.at(0).size() || row >= theGrid.size()) {
               currentBlock->setCells(cellCopy);
                return;
            }
        }
        emptyCellsInGrid(cellCopy);
        copyBlockIntoGrid(currentBlock);
    }
}

Block* Grid::getCurrentBlock() {
    return currentBlock;
}

Block * Grid::getNextBlock() {
    return nextBlock;
}
