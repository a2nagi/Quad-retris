#ifndef LEVEL_H
#define LEVEL_H

class Block;

class Level {
private:
    int level;
public:
    virtual Block getNextBlock(char nextBlock) = 0;
    virtual Block getNextBlock() = 0;
    virtual Level getNextLevel() = 0;
};
#endif
