#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

class Block;


class Level {
private:
    int counter;
    int level;
    std::vector<char> allChars;
    bool isRandom;
public:
    Level();
    virtual Block *getNextBlock() = 0;
    int getLevel() { return  level;};
    void setLevel(int level) {this->level = level;}
    void readFile(std::string file);
    void setRandomBlock(bool isRandom);
    bool getIsRandom();
    Block* getBlockFromFile();
    virtual ~Level();
};
#endif
