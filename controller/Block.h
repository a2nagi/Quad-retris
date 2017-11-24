#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

class Cell;
class Block {
protected:
    Cell *c1, *c2, *c3, *c4;
public:
    virtual void move() = 0;
    virtual void rotate() = 0;
    std::vector<Cell *> getCells() {
        std::vector<Cell *> allCells = {c1,c2,c3,c4};
        return allCells;
    }
    virtual ~Block();
};
#endif
