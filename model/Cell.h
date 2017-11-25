#ifndef CELL_H
#define CELL_H

#include <cstddef>
#include "subject.h"
#include "observer.h"

class Cell : public Subject, public Observer {
    const size_t r, c;
    char blockType;

public:
    Cell(size_t r, size_t c);

    void setPiece(char blockType);    // Place a piece of given colour here.

    void notify(Subject &whoFrom) override;// My neighbours will call this
    // when they've changed state
    Info getInfo() const override;
};

#endif //CELL_H
