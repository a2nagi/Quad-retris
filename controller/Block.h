#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <string>
#include "../model/Info.h"

class Cell;
enum Color {RED, BLACK, PEACH, SKIN, TEAL, VIOLET, BLUE};

class Block {
private:
    const int level;
protected:
    int updatedHeight;
    Cell *c1, *c2, *c3, *c4;
public:
    Block(int level);
    void move(Direction d);
    void rotate();
    std::vector<Cell *> getCells() {
        std::vector<Cell *> allCells = {c1,c2,c3,c4};
        return allCells;
    }
    std::vector<Cell *> copyCells();
    void setCells(std::vector<Cell*> allCells);
    virtual Color getColor()=0;
    virtual void setRotationHeight(int height)=0;
    virtual std::string toString()=0;
    int getHeight();
    std::vector<Cell *> getMinRows();
    int getMinCols();
    bool isBlockEmpty();
    int getLevel();
    virtual ~Block();
};
#endif
