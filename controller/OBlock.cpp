#include "OBlock.h"
#include "../model/Cell.h"

Color OBlock::getColor() {
    return Color::TEAL;
}

OBlock::OBlock(int level): Block(level) {
    c1 = new Cell(0, 0);
    c1->setPiece('O');

    c2 = new Cell(0, 1);
    c2->setPiece('O');

    c3 = new Cell(1, 0);
    c3->setPiece('O');

    c4 = new Cell(1,1);
    c4->setPiece('O');
}

void OBlock::setRotationHeight(int height)
{
    updatedHeight = 1;

}

std::string OBlock::toString() {
    return "OO\nOO";
}

