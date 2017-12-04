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
#include "../controller/JBlock.h"

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
    heavyCounter = 0;
    currentBlock = nullptr;
    nextBlock = nullptr;
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
    score = 0;
    heavyCounter = 0;
    for(unsigned int i = 0; i < theGrid.size(); i++) {
        for(unsigned int j =0; j < theGrid.at(0).size(); j++) {
            Info f = theGrid.at(i).at(j).getInfo();
            f.blockType = ' ';
            theGrid.at(i).at(j).setInfo(f);
        }
    }
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
    td = new TextDisplay(this);
    gd = new GraphicsDisplay(510, 700, this);
    for( int i = 0; i < rows; i++ ) {
        theGrid.emplace_back(vector<Cell>());
        for( int j = 0 ; j < cols ; j++ ) {
            theGrid.at(i).emplace_back(Cell(i, j));
            theGrid.at(i).at(j).attach(td);
            theGrid.at(i).at(j).attach(gd);
        }
    }
    highScore = max(highScore, score);
    currentLevel = allLevels.at(initialLevel);
    levelNumber = initialLevel;
    score = 0;
    currentBlock = currentLevel->getNextBlock();
    nextBlock = currentLevel->getNextBlock();
    changeBlockToGridCoordinates();
    copyBlockIntoGrid(currentBlock);
}

void Grid::moveToNextBlock() {
    currentBlock = nextBlock;
    if(currentBlock == nullptr) {
        throw gameOver();
    }
    nextBlock = currentLevel->getNextBlock();
    changeBlockToGridCoordinates();
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
//    if(isHintVisible)
//        return;
//    isHintVisible = true;
//    int  minRowSize = currentBlock->getMinRows().size();
//    unsigned int i = rows;
//    for(; i >=0; i --) {
//        for(unsigned int j = cols; j-minRowSize>= 0; j--) {
//            for(unsigned int k = 0; k < minRowSize; k++) {
//                if( theGrid.at(i).at(k).getInfo().blockType == ' ' )
//            }
//        }
//    }
//    // get the first
//    for(unsigned int i = rows-3; i >= 0; i--) {
//        int free = 0;
//        for(unsigned int j = cols; j >=0; i--) {
//
//        }
//    }
}

void Grid::eraseRow(int row) {
    if(row == 15) return;
    for( int i = 0; i < cols; i++ ) {
        Info f = theGrid.at(row+1).at(i).getInfo();
        theGrid.at(row).at(i).setPiece(f.blockType);
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
        emptyCellsInGrid(blocks);
        currentBlock->move(Direction::down);
        bool canMove = copyBlockIntoGrid(currentBlock);
        bool isRowErased = false;
        int timesErased = 0;
        if(canMove) {
            bool moveNext = false;
            for(Cell *c: blocks) {
                if(c->getInfo().row < 0) continue;
                if(isCurrentRowFull(c->getInfo().row)) {
                    eraseRow(c->getInfo().row);
                    // erase the block at the row
                    isRowErased = true;
                    placedBlocks.emplace_back(currentBlock);
                    vector<int> emptyArray;
                    timesErased++;
                    heavyCounter = 0;
                    for(unsigned int i =0; i < placedBlocks.size(); i++) {
                        for(Cell *c1: placedBlocks.at(i)->getCells()) {
                            if( c1->getInfo().row == c->getInfo().row) {
                                c1->setPiece(' ');
                            }
                        }
                    }

                    for(unsigned int i =0; i < placedBlocks.size(); i++) {
                        Block *b = placedBlocks.at(i);
                        if(b->isBlockEmpty()) {
                            score = score + (b->getLevel()+1) * (b->getLevel()+1);
                            emptyArray.emplace_back(i);
                        }
                    }
                    for(unsigned int i = 0; i < emptyArray.size(); i++) {
                        placedBlocks.erase(placedBlocks.begin()+ emptyArray.at(i) - i);
                    }

                    score = score + (levelNumber + 1)*(levelNumber+1);
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
                highScore = max(highScore, score);
                if(!isRowErased) {
                    placedBlocks.emplace_back(currentBlock);
                    if(this->levelNumber == 4 ) {
                        heavyCounter++;
                        if(heavyCounter%5 == 0) {
                            dropHeavyBlock();
                        }
                    }
                }
                else {
                    // remaing placed block each cell comes one row down.
                    for(unsigned int i =0; i < placedBlocks.size(); i++) {
                        for(Cell *c: placedBlocks.at(i)->getCells()) {
                            Info f = c->getInfo();
                            f.row-=timesErased;
                            c->setInfo(f);
                        }
                    }
                }
                moveToNextBlock();
                break;
            }
        }
        else {
            for(Cell *c: currentBlock->getCells()) {
                if(c->getInfo().row > 13) {
                    throw gameOver();
                }
            }
            currentBlock->move(Direction::up);
            copyBlockIntoGrid(currentBlock);
            moveToNextBlock();
            break;
        }
    }

    return canMove;

}

void Grid::dropHeavyBlock() {
    int middle = cols/2;
    for(int i = 0; i< rows; i++) {
        if(theGrid.at(i).at(middle).getInfo().blockType == ' ') {
            theGrid.at(i).at(middle).setPiece('*');
            return;
        }
    }
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
        if(theGrid.at(row).at(col).getInfo().blockType != ' ' ) {
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

void Grid::addObserverToCopy(std::vector<Cell *> cells) {
    for(Cell *c: cells) {
        c->attach(td);
    }
}

void Grid::moveCurrentBlockLeftRight(Direction d, int times) {
    bool done = false;
    for(int i = 0 ; i < times; i++) {
        vector<Cell*> blocks = currentBlock->getCells();
        vector<Cell *> cellCopy = currentBlock->copyCells();
        addObserverToCopy(cellCopy);
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
                done = true;
                break;
            }
        }
        emptyCellsInGrid(cellCopy);
        copyBlockIntoGrid(currentBlock);
        if(done) {
          break;
        }
    }
    if(this->levelNumber >= 3) {
        moveCurrentBlockDown(1);
    }
}

void Grid::replaceCurrentBlock(char block) {
    emptyCellsInGrid(currentBlock->getCells());
    delete currentBlock;
    currentBlock = currentLevel->getBlockByChar(block);
    changeBlockToGridCoordinates();
   // copyBlockIntoGrid(currentBlock);
}

void Grid::rotateBlock(int multiple) {
    vector<Cell*> cellCopy = currentBlock->copyCells();
    addObserverToCopy(cellCopy);
    for(int i = 0 ; i < multiple; i++) {
        currentBlock->rotate();
    }
    for(Cell *c : currentBlock->getCells()){
        unsigned int row = c->getInfo().row;
        unsigned int col = c->getInfo().col;
        if(col >= theGrid.at(0).size() || row >= theGrid.size()) {
            currentBlock->setCells(cellCopy);
            return;
        }
    }
    emptyCellsInGrid(cellCopy);
    copyBlockIntoGrid(currentBlock);
    if(this->levelNumber >= 3) {
        moveCurrentBlockDown(1);
    }
}

Block* Grid::getCurrentBlock() {
    return currentBlock;
}

Block * Grid::getNextBlock() {
    return nextBlock;
}
