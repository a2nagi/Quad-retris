#ifndef TBLOCK_H
#define TBLOCK_H
#include "Block.h"
class TBlock : public Block {
public:
    TBlock(int level);
    Color getColor()override;
    void setRotationHeight(int height)override;
    std::string toString() override ;
};
#endif //TBLOCK_H
