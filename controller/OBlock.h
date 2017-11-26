#ifndef OBLOCK_H
#define OBLOCK_H
#include "Block.h"
class OBlock : public Block {
public:
    OBlock();
    void move(Direction d);
    void rotate(Rotate r);
    Color getColor();
};
#endif //OBLOCK_H
