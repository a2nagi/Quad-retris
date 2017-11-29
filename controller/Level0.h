#ifndef LEVEL_H
#define LEVEL_H

class Block;

class Level {
public:
    Block* getNextBlock(char nextBlock = '') override;
};
#endif
