#ifndef LBLOCK_H
#define LBLOCK_H
#include "Block.h"
class LBlock : public Block {
public:
    LBlock();
    virtual void move();
    virtual void rotate();
};
#endif //LBLOCK_H
