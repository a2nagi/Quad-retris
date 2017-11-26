#ifndef ZBLOCK_H_H
#define ZBLOCK_H_H
#include "Block.h"
class ZBlock : public Block {
public:
    ZBlock();
    void move(Direction d);
    void rotate(Rotate r);
    Color getColor();
};

#endif //ZBLOCK_H
