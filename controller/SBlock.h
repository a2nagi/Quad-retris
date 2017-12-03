#ifndef SBLOCK_H
#define SBLOCK_H
#include "Block.h"
class SBlock : public Block {
public:
    SBlock(int level);
    Color getColor()override;
    void setRotationHeight(int height)override;
    std::string toString() override ;
};
#endif //SBLOCK_H
