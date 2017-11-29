#ifndef JBLOCK_H_H
#define JBLOCK_H_H
#include "Block.h"
class JBlock : public Block {
public:
    JBlock();
    Color getColor()override;
    void setRotationHeight(int height)override;
    void setRotationWidth(int width)override;
    ~JBlock();
};
#endif //JBLOCK_H
