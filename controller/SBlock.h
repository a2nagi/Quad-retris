#ifndef SBLOCK_H
#define SBLOCK_H
#include "Block.h"
class SBlock : public Block {
public:
    SBlock();
    Color getColor()override;
    void setRotationHeight(int height)override;
    void setRotationWidth(int width)override;
};
#endif //SBLOCK_H
