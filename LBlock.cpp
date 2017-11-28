#include "LBlock.h"

Color LBlock::getColor() {
    return Color::BLUE;
}

LBlock::LBlock() {
    Info l1;
    l1.row=0;
    l1.col=0;
    l1.blockType='L';
    c1->setInfo(l1);

    Info l2;
    l2.row=0;
    l2.col=1;
    l2.blockType='L';
    c2->setInfo(l2);

    Info l3;
    l3.row=0;
    l3.col=2;
    l3.blockType='L';
    c3->setInfo(l3);

    Info l4;
    l4.row=1;
    l4.col=2;
    l4.blockType='L';
    c4->setInfo(l4);
}
