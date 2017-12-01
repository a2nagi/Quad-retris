#include "Cell.h"
#include "Info.h"

Cell::Cell(size_t r, size_t c):r(r), c(c) {
    blockType = ' ';
}

void Cell::setPiece(char blockType) {
    this->blockType = blockType;
    notifyObservers();
}

bool Cell::setInfo(Info &i) {
    r = i.row;
    c = i.col;
    blockType = i.blockType;
    notifyObservers();
}

Info Cell::getInfo() const {
    return Info{r, c, blockType};
}
