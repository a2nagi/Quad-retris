#include "SBlock.h"
#include "../model/Cell.h"

Color SBlock::getColor() {
    return Color::VIOLET;
}

SBlock::SBlock()
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

void SBlock::setRotationWidth(int width) {
    if (width == 1)
    {
        updatedWidth = 2;
    }
    else
    {
        updatedWidth = 1;
    }
}

std::string SBlock::toString() {
    return " SS\nSS";
}
