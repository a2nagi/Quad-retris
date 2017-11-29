#ifndef LBLOCK_H
#define LBLOCK_H
#include "Block.h"
class LBlock : public Block {
public:
    LBlock();
    Color getColor()override;
    void setRotationHeight(int height)override;
    void setRotationWidth(int width)override;
    ~LBlock();
};
#endif //LBLOCK_H
