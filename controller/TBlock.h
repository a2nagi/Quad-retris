#ifndef TBLOCK_H
#define TBLOCK_H
#include "Block.h"
class TBlock : public Block {
public:
    TBlock();
    void move(Direction d);
    void rotate(Rotate r);
    Color getColor();
};
#endif //TBLOCK_H
