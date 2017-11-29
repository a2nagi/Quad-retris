#ifndef ZBLOCK_H_H
#define ZBLOCK_H_H
#include "Block.h"
class ZBlock : public Block {
public:
    ZBlock();
    Color getColor()override;
    void setRotationHeight(int height)override;
    void setRotationWidth(int width)override;
};

#endif //ZBLOCK_H
