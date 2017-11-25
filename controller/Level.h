#ifndef LEVEL_H
#define LEVEL_H

class Block;
class OperationNotSupported {};
class Level {
private:
    int level;
public:
    virtual Block getNextBlock(char nextBlock) {
        throw OperationNotSupported();
    };
    virtual Block getNextBlock() = 0;
    virtual Level getNextLevel() = 0;
};
#endif
