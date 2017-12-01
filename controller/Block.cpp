#include "Block.h"
#include "../model/Cell.h"

using namespace std;

//Block::Block(const Block &other)
//{
//    this->c1=new Cell(other.c1->getInfo().row,other.c1->getInfo().col);
//    this->c2=new Cell(other.c2->getInfo().row,other.c2->getInfo().col);
//    this->c3=new Cell(other.c3->getInfo().row,other.c3->getInfo().col);
//    this->c4=new Cell(other.c4->getInfo().row,other.c4->getInfo().col);
//}

Block::Block() {}
vector<Cell *> Block::copyCells() {
    vector<Cell *> allCells;
    allCells.emplace_back(new Cell(this->c1->getInfo().row, this->c1->getInfo().col));
    allCells.emplace_back(new Cell(this->c2->getInfo().row, this->c2->getInfo().col));
    allCells.emplace_back(new Cell(this->c3->getInfo().row, this->c3->getInfo().col));
    allCells.emplace_back(new Cell(this->c4->getInfo().row, this->c4->getInfo().col));
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

//Block& Block::operator=(const Block &other)
//{
//    if(this==&other)
//    {
//        return *this;
//    }
//    else
//    {
//        // a=b;
//        delete c1;
//        delete c2;
//        delete c3;
//        delete c4;
//        this->c1=new Cell(other.c1->getInfo().row,other.c1->getInfo().col);
//        this->c2=new Cell(other.c2->getInfo().row,other.c2->getInfo().col);
//        this->c3=new Cell(other.c3->getInfo().row,other.c3->getInfo().col);
//        this->c4=new Cell(other.c4->getInfo().row,other.c4->getInfo().col);
//        return *this;
//    }
//}

int Block::getHeight() {
    vector<Info> CellInfos;  // Vector of Cell infos except the Lower Left Preserved

    CellInfos.emplace_back(c1->getInfo());
    CellInfos.emplace_back(c2->getInfo());
    CellInfos.emplace_back(c3->getInfo());
    CellInfos.emplace_back(c4->getInfo());

    vector<int> calcHeight;
    for (int i = 0; i < CellInfos.size(); i++) {
        calcHeight.emplace_back(CellInfos.at(i).row);
    }

    int maxHeight=calcHeight.at(0);
    int minHeight=calcHeight.at(0);
    for (int j = 0; j < calcHeight.size(); j++)
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

int Block::getWidth()
{
    vector<Info> CellInfos(4);  // Vector of Cell infos except the Lower Left Preserved

    CellInfos.emplace_back(c1->getInfo());
    CellInfos.emplace_back(c2->getInfo());
    CellInfos.emplace_back(c3->getInfo());
    CellInfos.emplace_back(c4->getInfo());

    vector<int> calcWidth(4);
    for (int i = 0; i < CellInfos.size(); i++) {
        calcWidth.emplace_back(CellInfos.at(i).col);
    }


    int maxWidth=calcWidth.at(0);
    int minWidth=calcWidth.at(0);
    for (int j = 0; j < calcWidth.size(); j++)
    {
        if (calcWidth.at(j) > maxWidth)
        {
            maxWidth = calcWidth.at(j);
        }

        if (calcWidth.at(j) < minWidth)
        {
            minWidth = calcWidth.at(j);
        }
    }

    return maxWidth-minWidth;

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

    c1->setInfo(leftMost);
    c2->setInfo(nextToLeft);
    c3->setInfo(nextToRight);
    c4->setInfo(rightMost);

}


void Block::rotate(Rotate r)
{


    char colour=c1->getInfo().blockType;

    vector<Info> CellInfos;

    CellInfos.emplace_back(c1->getInfo());
    CellInfos.emplace_back(c2->getInfo());
    CellInfos.emplace_back(c3->getInfo());
    CellInfos.emplace_back(c4->getInfo());


    if (r == Rotate::clockWise)

    {
        int height = getHeight();
        setRotationHeight(height);

        for (int i = 0; i < CellInfos.size(); i++)
        {
            int newX = CellInfos.at(i).col;
            int newY = CellInfos.at(i).row;

            int transformX1 = newY;
            int transformY1 = newX;   // 1st flip, transformed x,y to be flipped along line of symmetry of figure.

            int transformX2 = transformX1;
            int transformY2 = updatedHeight - transformY1;   // 2nd flip , along line of symmetry of figure formed after 1st Transformation.


            CellInfos.at(i).row=transformX2;
            CellInfos.at(i).col=transformY2;
            CellInfos.at(i).blockType=colour;


        }

        c1->setInfo(CellInfos.at(0));
        c2->setInfo(CellInfos.at(1));
        c3->setInfo(CellInfos.at(2));
        c4->setInfo(CellInfos.at(3));
    }


    else if(r==Rotate::counterClockWise)

    {
        int width = getWidth();
        setRotationWidth(width);


        for (int i = 0; i < CellInfos.size(); i++)
        {
            int newX = CellInfos.at(i).col;
            int newY = CellInfos.at(i).row;

            int transformX1 = newY;
            int transformY1 = newX;   // 1st flip, transformed x,y to be flipped along line of symmetry of figure.

            int transformX2 = updatedWidth-transformX1;
            int transformY2 = transformY1;   // 2nd flip , along line of symmetry of figure formed after 1st Transformation.


            CellInfos.at(i).row=transformX2;
            CellInfos.at(i).col=transformY2;
            CellInfos.at(i).blockType=colour;
        }

        c1->setInfo(CellInfos.at(0));
        c2->setInfo(CellInfos.at(1));
        c3->setInfo(CellInfos.at(2));
        c4->setInfo(CellInfos.at(3));
    }
}

vector<Cell *> Block::getMinRows() {
    vector<Cell *> allCells = this->getCells();
    Cell *minCell = allCells.at(0);
    vector<Cell *> minCells;
    for(int i =1; i < allCells.size(); i++){
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

Block::~Block()
{
    delete c1;
    delete c2;
    delete c3;
    delete c4;
}
