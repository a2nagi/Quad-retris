#ifndef JBLOCK_H_H
#define JBLOCK_H_H
#include "Block.h"
class JBlock : public Block {
public:
    JBlock(int level);
    Color getColor()override;
    void setRotationHeight(int height)override;
    std::string toString() override;
};
#endif //JBLOCK_H
