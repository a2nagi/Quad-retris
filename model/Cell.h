#ifndef CELL_H
#define CELL_H

#include <cstddef>
#include "Subject.h"
#include "Observer.h"

class Cell : public Subject {
    size_t r, c;
    char blockType;
public:
    Cell(size_t r, size_t c);

    void setPiece(char blockType);    // Place a piece of given colour here.

    // when they've changed state
    Info getInfo() const override;
    void setInfo(Info &i);
    virtual ~Cell();
};

#endif //CELL_H
