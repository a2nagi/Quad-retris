#include "SBlock.h"
Color SBlock::getColor() {
    return Color::VIOLET;
}

SBlock::SBlock()
{
    Info s1;
    s1.row=3;
    s1.col=0;
    s1.blockType='S';
    c1->setInfo(s1);

    Info s2;
    s2.row=3;
    s2.col=1;
    s2.blockType='S';
    c2->setInfo(s2);

    Info s3;
    s3.row=2;
    s3.col=1;
    s3.blockType='S';
    c3->setInfo(s3);

    Info s4;
    s4.row=2;
    s4.col=2;
    s4.blockType='S';
    c4->setInfo(s4);
}

void SBlock::setRotationHeight(int height) {
    if (height == 1)
    {
        updatedHeight = 2;
    }
    else
    {
        updatedHeight = 1;
    }
}

void SBlock::setRotationWidth(int width) {
    if (width == 1)
    {
        updatedWidth = 2;
    }
    else
    {
        updatedWidth = 1;
    }
}

SBlock::~SBlock() {
    delete c1;
    delete c2;
    delete c3;
    delete c4;
}
