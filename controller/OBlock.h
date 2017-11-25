#ifndef OBLOCK_H
#define OBLOCK_H
#include "Block.h"
class OBlock : public Block {
public:
    OBlock();
    virtual void move();
    virtual void rotate();
};
#endif //OBLOCK_H
