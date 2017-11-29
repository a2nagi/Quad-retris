#include "LBlock.h"

Color LBlock::getColor() {
    return Color::BLUE;
}

LBlock::LBlock() {
    Info l1;
    l1.row=3;
    l1.col=0;
    l1.blockType='L';
    c1->setInfo(l1);

    Info l2;
    l2.row=3;
    l2.col=1;
    l2.blockType='L';
    c2->setInfo(l2);

    Info l3;
    l3.row=3;
    l3.col=2;
    l3.blockType='L';
    c3->setInfo(l3);

    Info l4;
    l4.row=2;
    l4.col=2;
    l4.blockType='L';
    c4->setInfo(l4);
}

void LBlock::setRotationHeight(int height) {
    if (height == 1)
    {
        updatedHeight = 2;
    }
    else
    {
        updatedHeight = 1;
    }
}

void LBlock::setRotationWidth(int width) {
    if (width == 1)
    {
        updatedWidth = 2;
    }
    else
    {
        updatedWidth = 1;
    }
}
