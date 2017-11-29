
#ifndef LEVEL1_H
#define LEVEL1_H

class Block;

class Level1 {
public:
    Block* getNextBlock(char nextBlock = '') override;
};
#endif
