#ifndef OBLOCK_H
#define OBLOCK_H
#include "Block.h"
class OBlock : public Block {
public:
    OBlock();
    Color getColor()override;
    void setRotationHeight(int height)override;
    void setRotationWidth(int width)override;
};
#endif //OBLOCK_H
