#ifndef GRID_H
#define GRID_H

#include <vector>

class Cell;
class Block;

class Grid {
private:
    std::vector<std::vector<Cell>> grid;
    Block* currentBlock;
    int level;
    int score;
public:
    void insertNewBlock(Block *currentBlock);
    void updateCurrentBlock();
    void getLevel();
    void getScore();
};
#endif //GRID_H
