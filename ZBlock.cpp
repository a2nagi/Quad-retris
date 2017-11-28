#include "ZBlock.h"
Color ZBlock::getColor() {
    return Color::PEACH;
}

ZBlock::ZBlock() {

    Info z1;
    z1.row=2;
    z1.col=0;
    z1.blockType='Z';
    c1->setInfo(z1);

    Info z2;
    z2.row=2;
    z2.col=1;
    z2.blockType='Z';
    c2->setInfo(z2);

    Info z3;
    z3.row=3;
    z3.col=1;
    z3.blockType='Z';
    c3->setInfo(z3);

    Info z4;
    z4.row=3;
    z4.col=2;
    z4.blockType='Z';
    c4->setInfo(z4);
}