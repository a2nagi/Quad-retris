#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

class Block;


class Level {
private:
    unsigned int counter;
    int level;
    std::vector<char> allChars;
    bool isRandom;
public:
    Level();
    virtual Block *getNextBlock() = 0;
    int getLevel();
    void setLevel(int level);
    void readFile(std::string file);
    void setRandomBlock(bool isRandom);
    bool getIsRandom();
    Block* getBlockFromFile();
    Block* getBlockByChar(char block);
    virtual ~Level();
};
#endif
