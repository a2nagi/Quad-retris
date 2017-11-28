#ifndef GRID_H
#define GRID_H

#include <vector>
#include "../controller/Level.h"
#include "State.h"

class Cell;
class Block;
class Info;

class gameOver{};
class Grid {
private:
    std::vector<std::vector<Cell>> theGrid;
    Block* currentBlock;
    Block* nextBlock;
    Level* currentLevel;
    int score;
    int cols;
    int rows;
    int highScore;
    int levelNumber;
    bool isCurrentRowFull();
    //void getNextBlock();
    void updateLevel(int requestedLevel);
    bool copyBlockIntoGrid(Block * block);
public:
    Grid();
    void initGrid();
    void dropBlock();
    void insertNewBlock(Block *block);
    void updateCurrentBlock();
    int getLevel();
    int getScore();
    int getHighScore();
    void moveCurrentBlockLeftRight(Direction d);
    void rotateBlock(Rotate r);
    void moveCurrentBlockDown();
    void nextLevel();
    void levelDown();
    Block* getCurrentBlock();
    Block* getNextBlock();
    void changeBlockToGridCoordinates();
};
#endif //GRID_H
