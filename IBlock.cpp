#include "IBlock.h"

Color IBlock::getColor() {
   return Color::RED;
}

IBlock::IBlock() {
    Info i1;
    i1.row=3;
    i1.col=0;
    i1.blockType='I';
    c1->setInfo(i1);

    Info i2;
    i2.row=3;
    i2.col=1;
    i2.blockType='I';
    c2->setInfo(i2);

    Info i3;
    i3.row=3;
    i3.col=2;
    i3.blockType='I';
    c3->setInfo(i3);

    Info i4;
    i4.row=3;
    i4.col=3;
    i4.blockType='I';
    c4->setInfo(i4);
}