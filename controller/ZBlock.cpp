#include "ZBlock.h"
#include "../model/Cell.h"

Color ZBlock::getColor() {
    return Color::PEACH;
}

ZBlock::ZBlock() {

    c1 = new Cell(1, 0);
    c1->setPiece('Z');

    c2 = new Cell(1,1);
    c2->setPiece('Z');

    c3 = new Cell(0, 1);
    c3->setPiece('Z');

    c4 = new Cell(0, 2);
    c4->setPiece('Z');

}

void ZBlock::setRotationHeight(int height) {
    if (height == 1)
    {
        updatedHeight = 2;
    }
    else
    {
        updatedHeight = 1;
    }
}

void ZBlock::setRotationWidth(int width) {
    if (width == 1)
    {
        updatedWidth = 2;
    }
    else
    {
        updatedWidth = 1;
    }
}

std::string ZBlock::toString() {
    return "ZZ\n ZZ";
}
