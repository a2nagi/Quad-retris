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

    void setPiece(Colour colour);    // Place a piece of given colour here.
    void toggle();         // Toggles my colour.

    void notify(Subject<Info, State> &whoFrom) override;// My neighbours will call this
    // when they've changed state
    Info getInfo() const override;
};

#endif //CELL_H
