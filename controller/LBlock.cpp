#include "LBlock.h"
#include "../model/Cell.h"

Color LBlock::getColor() {
    return Color::BLUE;
}

LBlock::LBlock() {
    c1 = new Cell(0, 0);
    c1->setPiece('L');

    c2 = new Cell(0, 1);
    c2->setPiece('L');

    c3 = new Cell(0, 2);
    c3->setPiece('L');

    c4 = new Cell(1, 2);
    c4->setPiece('L');
}

void LBlock::setRotationHeight(int height) {
    if (height == 1)
    {
        updatedHeight = 2;
    }
    else
    {
        updatedHeight = 1;
    }
}

void LBlock::setRotationWidth(int width) {
    if (width == 1)
    {
        updatedWidth = 2;
    }
    else
    {
        updatedWidth = 1;
    }
}

std::string LBlock::toString() {
    return "  L\nLLL";
}
