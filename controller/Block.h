#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <string>
#include "../model/Info.h"

class Cell;
enum Color {RED, BLACK, PEACH, SKIN, TEAL, VIOLET, BLUE};

class Block {
protected:
    int updatedHeight;
    int updatedWidth;
    Cell *c1, *c2, *c3, *c4;
public:
    Block();
//    Block(const Block& other);
//    Block& operator=(const Block &other);
    void move(Direction d);
    void rotate();
    std::vector<Cell *> getCells() {
        std::vector<Cell *> allCells = {c1,c2,c3,c4};
        return allCells;
    }
    std::vector<Cell *> copyCells();
    void setCells(std::vector<Cell*> allCells);
    virtual Color getColor()=0;
    virtual void setRotationWidth(int width)=0;
    virtual void setRotationHeight(int height)=0;
    virtual std::string toString()=0;
    int getHeight();
    int getWidth();
    std::vector<Cell *> getMinRows();
    virtual ~Block();
};
#endif
