#ifndef LBLOCK_H
#define LBLOCK_H
#include "Block.h"
class LBlock : public Block {
public:
    LBlock();
    Color getColor()override;
    void setRotationHeight(int height)override;
    void setRotationWidth(int width)override;
};
#endif //LBLOCK_H
