#include <iostream>
#include "IBlock.h"
#include "../model/Cell.h"

using namespace std;

Color IBlock::getColor() {
   return Color::RED;
}

IBlock::IBlock() {

    c1 = new Cell(0, 0);
    c1->setPiece('I');

    c2 = new Cell(0, 1);
    c2->setPiece('I');

    c3 = new Cell(0, 2);
    c3->setPiece('I');

    c4 = new Cell(0,3);
    c4->setPiece('I');
}

void IBlock::setRotationHeight(int height)
{
    if (height == 0)
    {
        updatedHeight = 3;
    }
    else
    {
        updatedHeight = 0;
    }

}

void IBlock::setRotationWidth(int width) {
    if (width == 0)
    {
        updatedWidth = 3;
    }
    else
    {
        updatedWidth = 0;
    }

}

string IBlock::toString() {
    return "IIII";
}
