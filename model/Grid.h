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
    bool isCurrentRowFull(int row);
    //void getNextBlock();
    void updateLevel(int requestedLevel);
    bool copyBlockIntoGrid(Block * block);
    void eraseRow(int row);
public:
    Grid();
    void initGrid();
    void dropBlock();
    int getLevel();
    int getScore();
    int getHighScore();
    void moveCurrentBlockLeftRight(Direction d);
    void rotateBlock(Rotate r);
    bool moveCurrentBlockDown();
    void nextLevel();
    void levelDown();
    Block* getCurrentBlock();
    Block* getNextBlock();
    void changeBlockToGridCoordinates();
    void showHint();
};
#endif //GRID_H
