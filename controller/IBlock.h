#ifndef IBLOCK_H_H
#define IBLOCK_H_H

#include "Block.h"
class IBlock : public Block {

public:
    IBlock(int level);
    Color getColor()override;
    void setRotationHeight(int height)override;
    std::string toString() override ;
};
#endif //IBLOCK_H
