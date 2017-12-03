#ifndef LBLOCK_H
#define LBLOCK_H
#include "Block.h"
class LBlock : public Block {
public:
    LBlock(int level);
    Color getColor()override;
    void setRotationHeight(int height)override;
    std::string toString() override ;
};
#endif //LBLOCK_H
