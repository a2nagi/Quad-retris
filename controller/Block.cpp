#include "Block.h"
#include "../model/Cell.h"


using namespace std;

Block::Block(int level): level(level) {}

vector<Cell *> Block::copyCells() {
    vector<Cell *> allCells;
    allCells.emplace_back(new Cell(this->c1->getInfo().row, this->c1->getInfo().col));
    allCells.emplace_back(new Cell(this->c2->getInfo().row, this->c2->getInfo().col));
    allCells.emplace_back(new Cell(this->c3->getInfo().row, this->c3->getInfo().col));
    allCells.emplace_back(new Cell(this->c4->getInfo().row, this->c4->getInfo().col));
    allCells.at(0)->setPiece(this->c1->getInfo().blockType);
    allCells.at(1)->setPiece(this->c2->getInfo().blockType);
    allCells.at(2)->setPiece(this->c3->getInfo().blockType);
    allCells.at(3)->setPiece(this->c4->getInfo().blockType);
    return allCells;
}

void Block::setCells(std::vector<Cell *> allCells) {
    delete c1;
    delete c2;
    delete c3;
    delete c4;
    c1 = allCells.at(0);
    c2 = allCells.at(1);
    c3 = allCells.at(2);
    c4 = allCells.at(3);
    c1->notifyObservers();
    c2->notifyObservers();
    c3->notifyObservers();
    c4->notifyObservers();
}

int Block::getHeight() {
    vector<Info> CellInfos;  // Vector of Cell infos except the Lower Left Preserved

    CellInfos.emplace_back(c1->getInfo());
    CellInfos.emplace_back(c2->getInfo());
    CellInfos.emplace_back(c3->getInfo());
    CellInfos.emplace_back(c4->getInfo());

    vector<int> calcHeight;
    for (unsigned int i = 0; i < CellInfos.size(); i++) {
        calcHeight.emplace_back(CellInfos.at(i).row);
    }

    int maxHeight=calcHeight.at(0);
    int minHeight=calcHeight.at(0);
    for (unsigned int j = 0; j < calcHeight.size(); j++)
    {
        if (calcHeight.at(j) > maxHeight)
        {
            maxHeight = calcHeight.at(j);
        }

        if (calcHeight.at(j) < minHeight)
        {
            minHeight = calcHeight.at(j);
        }
    }

    // calculate height in above two loops.

    return maxHeight-minHeight;
}

void Block::move(Direction d){

    Info leftMost=c1->getInfo();
    Info nextToLeft=c2->getInfo();
    Info nextToRight=c3->getInfo();
    Info rightMost=c4->getInfo();

    if(d==Direction::left)
    {
        leftMost.col-=1;
        nextToLeft.col-=1;
        nextToRight.col-=1;
        rightMost.col-=1;

    }

    else if(d==Direction::right)
    {
        leftMost.col+=1;
        nextToLeft.col+=1;
        nextToRight.col+=1;
        rightMost.col+=1;

    }


    else if(d==Direction::down)
    {
        leftMost.row-=1;
        nextToLeft.row-=1;
        nextToRight.row-=1;
        rightMost.row-=1;
    }
    else if(d==Direction::up) {
        leftMost.row+=1;
        nextToLeft.row+=1;
        nextToRight.row+=1;
        rightMost.row+=1;
    }
    c1->setInfo(leftMost);
    c2->setInfo(nextToLeft);
    c3->setInfo(nextToRight);
    c4->setInfo(rightMost);

}


void Block::rotate()
{
    char colour=c1->getInfo().blockType;
    vector<Info> CellInfos;

    CellInfos.emplace_back(c1->getInfo());
    CellInfos.emplace_back(c2->getInfo());
    CellInfos.emplace_back(c3->getInfo());
    CellInfos.emplace_back(c4->getInfo());


    int height = getHeight();
    setRotationHeight(height);


    for (unsigned int i = 0; i < CellInfos.size(); i++) {

        int minCols=getMinCols();
        int rowMin=this->getMinRows().at(0)->getInfo().row;

        int curX = CellInfos.at(i).row - rowMin;
        int curY = CellInfos.at(i).col-minCols;

        int tr1X = curY;
        int tr1Y = curX;

        int tr2Y = tr1Y+minCols;
        int tr2X = updatedHeight-tr1X+rowMin;



            CellInfos.at(i).row=tr2X;
            CellInfos.at(i).col=tr2Y;
            CellInfos.at(i).blockType=colour;

        }

        c1->setInfo(CellInfos.at(0));
        c2->setInfo(CellInfos.at(1));
        c3->setInfo(CellInfos.at(2));
        c4->setInfo(CellInfos.at(3));
}


vector<Cell *> Block::getMinRows() {
    vector<Cell *> allCells = this->getCells();
    Cell *minCell = allCells.at(0);
    vector<Cell *> minCells;
    for(unsigned int i =1; i < allCells.size(); i++){
        if(minCell->getInfo().row > allCells.at(i)->getInfo().row) {
            minCell = allCells.at(i);
        }
    }
    for(Cell *c: this->getCells()) {
        if(c->getInfo().row == minCell->getInfo().row) {
            minCells.emplace_back(c);
        }
    }
    return minCells;
}

int Block::getMinCols() {
    vector<Info> CellInfos;  // Vector of Cell infos except the Lower Left Preserved

    CellInfos.emplace_back(c1->getInfo());
    CellInfos.emplace_back(c2->getInfo());
    CellInfos.emplace_back(c3->getInfo());
    CellInfos.emplace_back(c4->getInfo());

    vector<int> calcWidth;
    for (int i = 0; i < CellInfos.size(); i++) {
        calcWidth.emplace_back(CellInfos.at(i).col);
    }

    int minWidth=calcWidth.at(0);
    for (int j = 0; j < calcWidth.size(); j++)
    {

        if (calcWidth.at(j) < minWidth)
        {
            minWidth = calcWidth.at(j);
        }
    }
    return minWidth;
}

bool Block::isBlockEmpty() {
    return c1->getInfo().blockType == ' ' && c2->getInfo().blockType == ' '
           && c3->getInfo().blockType == ' ' && c4->getInfo().blockType == ' ';
}

int Block::getLevel() {
    return level;
}

Block::~Block()
{
    delete c1;
    delete c2;
    delete c3;
    delete c4;
}
