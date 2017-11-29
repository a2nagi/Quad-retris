#ifndef LEVEL3_H
#define LEVEL3_H

#include <iostream>
#include <cstdlib>

class Block;

class Level {
public:
   Block *getNextBlock(char nextBlock = '');
};
#endif
