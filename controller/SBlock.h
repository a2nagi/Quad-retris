#ifndef SBLOCK_H
#define SBLOCK_H
#include "Block.h"
class SBlock : public Block {
public:
    SBlock();
    void move(Direction d);
    void rotate(Rotate r);
    Color getColor();
};
#endif //SBLOCK_H
