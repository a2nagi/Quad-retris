#ifndef JBLOCK_H_H
#define JBLOCK_H_H
#include "Block.h"
class JBlock : public Block {
public:
    JBlock();
    virtual void move();
    virtual void rotate();
};
#endif //JBLOCK_H
