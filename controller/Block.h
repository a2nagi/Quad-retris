#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include "../model/State.h"

class Cell;
enum Color {RED, BLACK, PEACH, SKIN, TEAL, VIOLET, BLUE};
class Block {
protected:
    Cell *c1, *c2, *c3, *c4;
public:
    Block(char whichBlock);
    Block(const Block& other);
    Block& operator=(const Block &b);
    virtual void move(Direction d);
    virtual void rotate(Rotate r);
    std::vector<Cell *> getCells() {
        std::vector<Cell *> allCells = {c1,c2,c3,c4};
        return allCells;
    }
    virtual Color getColor() = 0;
    virtual ~Block();
};
#endif
