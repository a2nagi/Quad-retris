#ifndef LBLOCK_H
#define LBLOCK_H
#include "Block.h"
class LBlock : public Block {
public:
    LBlock();
    void move(Direction d);
    void rotate(Rotate r);
    Color getColor();
};
#endif //LBLOCK_H
