#ifndef ZBLOCK_H_H
#define ZBLOCK_H_H
#include "Block.h"
class ZBlock : public Block {
public:
    ZBlock();
    virtual void move();
    virtual void rotate();
};

#endif //ZBLOCK_H
