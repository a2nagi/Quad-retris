#include "SBlock.h"
#include "../model/Cell.h"

Color SBlock::getColor() {
    return Color::VIOLET;
}

SBlock::SBlock(int level): Block(level)
{
    c1 = new Cell(0, 0);
    c1->setPiece('S');

    c2 = new Cell(1,1);
    c2->setPiece('S');

    c3 = new Cell(0, 1);
    c3->setPiece('S');

    c4 = new Cell(1, 2);
    c4->setPiece('S');

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

std::string SBlock::toString() {
    return " SS\nSS";
}
