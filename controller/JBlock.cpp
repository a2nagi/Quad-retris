#include "JBlock.h"
#include "../model/Cell.h"

using namespace std;

Color JBlock::getColor() {
    return Color::BLACK;
}


JBlock::JBlock() {
    c1 = new Cell(0, 0);
    c1->setPiece('J');

    c2 = new Cell(1, 0);
    c2->setPiece('J');

    c3 = new Cell(0, 1);
    c3->setPiece('J');

    c4 = new Cell(0, 2);
    c4->setPiece('J');

}

void JBlock::setRotationHeight(int height) {
    if (height == 1)
    {
        updatedHeight = 2;
    }
    else
    {
        updatedHeight = 1;
    }
}

void JBlock::setRotationWidth(int width) {
    if (width == 1)
    {
        updatedWidth = 2;
    }
    else
    {
        updatedWidth = 1;
    }
}

string JBlock::toString() {
    return "J\nJJJ";
}

