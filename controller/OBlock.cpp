#include "OBlock.h"
#include "../model/Cell.h"

Color OBlock::getColor() {
    return Color::TEAL;
}

OBlock::OBlock() {
    Info o1;
    o1.row=3;
    o1.col=0;
    o1.blockType='O';
    c1->setInfo(o1);

    Info o2;
    o2.row=3;
    o2.col=1;
    o2.blockType='O';
    c2->setInfo(o2);

    Info o3;
    o3.row=2;
    o3.col=0;
    o3.blockType='O';
    c3->setInfo(o3);

    Info o4;
    o4.row=2;
    o4.col=1;
    o4.blockType='O';
    c4->setInfo(o4);
}

void OBlock::setRotationHeight(int height)
{
    updatedHeight = 1;

}

void OBlock::setRotationWidth(int width) {
    updatedWidth=1;

}

