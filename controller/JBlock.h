#ifndef JBLOCK_H_H
#define JBLOCK_H_H
#include "Block.h"
class JBlock : public Block {
public:
    JBlock();
    void move(Direction d);
    void rotate(Rotate r);
    Color getColor();
};
#endif //JBLOCK_H
