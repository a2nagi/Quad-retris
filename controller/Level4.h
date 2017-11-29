#ifndef LEVEL4_H
#define LEVEL4_H

class Block;

class Level {
public:
    Block *getNextBlock(char nextBlock = '') override;
};
#endif
