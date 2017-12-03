#ifndef OBLOCK_H
#define OBLOCK_H
#include "Block.h"
class OBlock : public Block {
public:
    OBlock(int level);
    Color getColor()override;
    void setRotationHeight(int height)override;
    std::string toString() override ;
};
#endif //OBLOCK_H
