#include "JBlock.h"
#include "../model/Cell.h"

Color JBlock::getColor() {
    return Color::BLACK;
}


JBlock::JBlock() {
    Info j1;
    j1.row=2;
    j1.col=0;
    j1.blockType='J';
    c1->setInfo(j1);

    Info j2;
    j2.row=3;
    j2.col=0;
    j2.blockType='J';
    c2->setInfo(j2);

    Info i3;
    i3.row=3;
    i3.col=1;
    i3.blockType='J';
    c3->setInfo(i3);

    Info j4;
    j4.row=3;
    j4.col=2;
    j4.blockType='J';
    c4->setInfo(j4);
}

void JBlock::setRotationHeight(int height) {
    if (height == 1)
    {
        updatedHeight = 2;
    }
    else
    {
        updatedHeight = 1;
    }
}

void JBlock::setRotationWidth(int width) {
    if (width == 1)
    {
        updatedWidth = 2;
    }
    else
    {
        updatedWidth = 1;
    }
}


