#ifndef ZBLOCK_H_H
#define ZBLOCK_H_H
#include "Block.h"
class ZBlock : public Block {
public:
    ZBlock(int level);
    Color getColor()override;
    void setRotationHeight(int height)override;
    std::string toString() override ;
};

#endif //ZBLOCK_H
