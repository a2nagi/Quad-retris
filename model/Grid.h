#ifndef GRID_H
#define GRID_H

#include <vector>
#include "../controller/Level.h"
#include "State.h"
#include <string>

class Cell;
class Block;
class Info;
class TextDisplay;

class gameOver{};
class Grid {
private:
    std::vector<std::vector<Cell>> theGrid;
    std::vector<Level *> allLevels;
    Block* currentBlock;
    Block* nextBlock;
    Level* currentLevel;
    int score;
    int cols;
    int rows;
    int highScore;
    int levelNumber;
    bool isHintVisible;
    bool isCurrentRowFull(int row);
    void updateLevel(int requestedLevel);
    bool copyBlockIntoGrid(Block * block);
    void eraseRow(int row);
    void emptyCellsInGrid(std::vector<Cell *> cells);
    void moveToNextBlock();
    void dropHeavyBlock();
    void addObserverToCopy(std::vector<Cell *> cells);
    TextDisplay *td;
    int heavyCounter;
public:
    Grid();
    int getRows();
    int getColumns();
    void initGrid(std::string fileName, int initialLevel, bool isTextOnly);
    void dropBlock();
    int getLevel();
    int getScore();
    int getHighScore();
    void moveCurrentBlockLeftRight(Direction d, int times);
    void rotateBlock(int multiple);
    bool moveCurrentBlockDown(int times);
    void nextLevel(int counter);
    void levelDown(int counter);
    Block* getCurrentBlock();
    Block* getNextBlock();
    void changeBlockToGridCoordinates();
    void showHint();
    TextDisplay* getTextDisplay();
    void makeCurrentLevelFromFile(std::string fileName);
    void makeCurrentLevelRandom();
    void replaceCurrentBlock(char block);
    void clearGrid();
    std::vector<Block * > placedBlocks;
    ~Grid();
};
#endif //GRID_H
