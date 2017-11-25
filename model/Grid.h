#ifndef GRID_H
#define GRID_H

#include <vector>

class Cell;
class Block;

class Grid {
private:
    std::vector<std::vector<Cell>> grid;
    Block* currentBlock;
public:
    void insertNewBlock(Block *currentBlock);
    void updateCurrentBlock();
};
#endif //GRID_H
