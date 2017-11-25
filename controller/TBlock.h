#ifndef TBLOCK_H
#define TBLOCK_H
#include "Block.h"
class TBlock : public Block {
public:
    TBlock();
    virtual void move();
    virtual void rotate();
};
#endif //TBLOCK_H
