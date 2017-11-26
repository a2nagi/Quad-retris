#ifndef IBLOCK_H_H
#define IBLOCK_H_H

#include "Block.h"
class IBlock : public Block {
public:
    IBlock();
    void move(Direction d);
    void rotate(Rotate r);
    void getColor();
};
#endif //IBLOCK_H
