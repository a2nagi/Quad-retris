#include "TBlock.h"
#include "../model/Cell.h"

Color TBlock::getColor() {
    return Color::SKIN;
}

TBlock::TBlock()
{
    c1 = new Cell(0, 1);
    c1->setPiece('T');

    c2 = new Cell(1, 0);
    c2->setPiece('T');

    c3 = new Cell(1, 1);
    c3->setPiece('T');

    c4 = new Cell(1, 2);
    c4->setPiece('T');

}

void TBlock::setRotationHeight(int height) {
    if (height == 1)
    {
        updatedHeight = 2;
    }
    else
    {
        updatedHeight = 1;
    }
}

void TBlock::setRotationWidth(int width) {
    if (width == 1)
    {
        updatedWidth = 2;
    }
    else
    {
        updatedWidth = 1;
    }
}

std::string TBlock::toString() {
    return "TTT\n T ";
}
