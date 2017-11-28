#include "JBlock.h"

Color JBlock::getColor() {
    return Color::BLACK;
}


JBlock::JBlock() {
    Info j1;
    j1.row=0;
    j1.col=0;
    j1.blockType='J';
    c1->setInfo(j1);

    Info j2;
    j2.row=0;
    j2.col=1;
    j2.blockType='J';
    c2->setInfo(j2);

    Info i3;
    i3.row=0;
    i3.col=2;
    i3.blockType='J';
    c3->setInfo(i3);

    Info j4;
    j4.row=1;
    j4.col=0;
    j4.blockType='J';
    c4->setInfo(j4);
}
