#include "TBlock.h"
Color TBlock::getColor() {
    return Color::SKIN;
}

TBlock::TBlock()
{
    Info t1;
    t1.row=0;
    t1.col=1;
    t1.blockType='T';
    c1->setInfo(t1);

    Info t2;
    t2.row=1;
    t2.col=0;
    t2.blockType='T';
    c2->setInfo(t2);

    Info t3;
    t3.row=1;
    t3.col=1;
    t3.blockType='T';
    c3->setInfo(t3);

    Info t4;
    t4.row=1;
    t4.col=2;
    t4.blockType='T';
    c4->setInfo(t4);
}
