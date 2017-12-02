#ifndef LEVEL_H
#define LEVEL_H

class Block;


class Level {
private:
    int level;
public:
    virtual Block *getNextBlock() = 0;
    int getLevel() { return  level;};
    void setLevel(int level) {this->level = level;}
    virtual ~Level(){};
};
#endif
