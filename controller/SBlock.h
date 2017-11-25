#ifndef SBLOCK_H
#define SBLOCK_H
#include "Block.h"
class SBlock : public Block {
public:
    SBlock();
    virtual void move();
    virtual void rotate();
};
#endif //SBLOCK_H
