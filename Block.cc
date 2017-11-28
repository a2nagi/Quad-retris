#include "Block.h"
using namespace std;

char Block ::getColor()
{
    return c1->getInfo().blockType; // check again if you can just change return type of getColor to char from enum Color
}

Block::Block(Block &other)
{
    this->c1=new Cell(other.c1->getInfo().row,other.c1->getInfo().col);
    this->c2=new Cell(other.c2->getInfo().row,other.c2->getInfo().col);
    this->c3=new Cell(other.c3->getInfo().row,other.c3->getInfo().col);
    this->c4=new Cell(other.c4->getInfo().row,other.c4->getInfo().col);

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


void Block::rotate(Rotate r)
{


    char colour=c1->getInfo().blockType;

    vector<Info> CellInfos(4);  // Vector of Cell infos except the Lower Left Preserved

    CellInfos.emplace_back(c1->getInfo());
    CellInfos.emplace_back(c2->getInfo());
    CellInfos.emplace_back(c3->getInfo());
    CellInfos.emplace_back(c4->getInfo());


    if (r == Rotate::clockWise)

    {

        vector<int> calcHeight(4);
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

        int height=maxHeight-minHeight;
        int updatedHeight;

        if (colour == 'S' || colour == 'Z' || colour == 'T' || colour == 'L' || colour == 'J') {

            if (height == 1)
            {
                updatedHeight = 2;
            }
            else
            {
                updatedHeight = 1;
            }
        }

        else if (colour == 'O') {
            updatedHeight = 1;
        }

        else if (colour == 'I')
        {
            if (height == 0)
            {
                updatedHeight = 3;
            }
            else
            {
                updatedHeight = 0;
            }

        }

        for (int i = 0; i < CellInfos.size(); i++) {
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

        // setInfos for all Cells

        c1->setInfo(CellInfos.at(0));
        c2->setInfo(CellInfos.at(1));
        c3->setInfo(CellInfos.at(2));
        c4->setInfo(CellInfos.at(3));
    }


    else if(r==Rotate::counterClockWise)

    {
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

        int width=maxWidth-minWidth;
        int updatedWidth;


        if (colour == 'S' || colour == 'Z' || colour == 'T' || colour == 'L' || colour == 'J') {

            if (width == 1)
            {
                updatedWidth = 2;
            }
            else
            {
                updatedWidth = 1;
            }
        }

        else if (colour == 'O') {
            updatedWidth = 1;
        }

        else if (colour == 'I')
        {
            if (width == 0)
            {
                updatedWidth = 3;
            }
            else
            {
                updatedWidth = 0;
            }

        }

        for (int i = 0; i < CellInfos.size(); i++) {
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

        // setInfos for all Cells

        c1->setInfo(CellInfos.at(0));
        c2->setInfo(CellInfos.at(1));
        c3->setInfo(CellInfos.at(2));
        c4->setInfo(CellInfos.at(3));

    }
}

