#include "Block.h"
using namespace std;

char Block ::getColor()
{
    return c1->getInfo().blockType; // check again if you can just change return type of getColor to char from enum Color
}

Block::Block(const Block &other)
{
    this->c1=new Cell(other.c1->getInfo().row,other.c1->getInfo().col);
    this->c2=new Cell(other.c2->getInfo().row,other.c2->getInfo().col);
    this->c3=new Cell(other.c3->getInfo().row,other.c3->getInfo().col);
    this->c4=new Cell(other.c4->getInfo().row,other.c4->getInfo().col);

}

Block& Block::operator=(Block &other)
{
    if(this==&other)
    {
        return *this;
    }
    else
    {
        // a=b;
        delete c1;
        delete c2;
        delete c3;
        delete c4;
        this->c1=new Cell(other.c1->getInfo().row,other.c1->getInfo().col);
        this->c2=new Cell(other.c2->getInfo().row,other.c2->getInfo().col);
        this->c3=new Cell(other.c3->getInfo().row,other.c3->getInfo().col);
        this->c4=new Cell(other.c4->getInfo().row,other.c4->getInfo().col);
        return *this;
    }
}

Block::Block(char whichBlock)
{
    if(whichBlock=='I')
    {
        Info i1;
        i1.row=0;
        i1.col=0;
        i1.blockType='I';
        c1->setInfo(i1);

        Info i2;
        i2.row=0;
        i2.col=1;
        i2.blockType='I';
        c2->setInfo(i2);

        Info i3;
        i3.row=0;
        i3.col=2;
        i3.blockType='I';
        c3->setInfo(i3);

        Info i4;
        i4.row=0;
        i4.col=3;
        i4.blockType='I';
        c4->setInfo(i4);
    }

    else if(whichBlock=='O')
    {
        Info o1;
        o1.row=0;
        o1.col=0;
        o1.blockType='O';
        c1->setInfo(o1);

        Info o2;
        o2.row=0;
        o2.col=1;
        o2.blockType='O';
        c2->setInfo(o2);

        Info o3;
        o3.row=1;
        o3.col=0;
        o3.blockType='O';
        c3->setInfo(o3);

        Info o4;
        o4.row=1;
        o4.col=1;
        o4.blockType='O';
        c4->setInfo(o4);
    }

    else if (whichBlock=='T')
    {
        Info t1;
        t1.row=0;
        t1.col=1;
        t1.blockType='T';
        c1->setInfo(t1);

        Info t2;
        t2.row=1;
        t2.col=0;
        t2.blockType='T';
        c2->setInfo(t2);

        Info t3;
        t3.row=1;
        t3.col=1;
        t3.blockType='T';
        c3->setInfo(t3);

        Info t4;
        t4.row=1;
        t4.col=2;
        t4.blockType='T';
        c4->setInfo(t4);
    }

    else if(whichBlock=='S')
    {
        Info s1;
        s1.row=0;
        s1.col=0;
        s1.blockType='S';
        c1->setInfo(s1);

        Info s2;
        s2.row=0;
        s2.col=1;
        s2.blockType='S';
        c2->setInfo(s2);

        Info s3;
        s3.row=1;
        s3.col=1;
        s3.blockType='S';
        c3->setInfo(s3);

        Info s4;
        s4.row=1;
        s4.col=2;
        s4.blockType='S';
        c4->setInfo(s4);
    }

    else if(whichBlock=='Z')
    {

        Info z1;
        z1.row=0;
        z1.col=1;
        z1.blockType='Z';
        c1->setInfo(z1);

        Info z2;
        z2.row=0;
        z2.col=2;
        z2.blockType='Z';
        c2->setInfo(z2);

        Info z3;
        z3.row=1;
        z3.col=0;
        z3.blockType='Z';
        c3->setInfo(z3);

        Info z4;
        z4.row=1;
        z4.col=1;
        z4.blockType='Z';
        c4->setInfo(z4);
    }

    else if(whichBlock=='L')
    {
        Info l1;
        l1.row=0;
        l1.col=0;
        l1.blockType='L';
        c1->setInfo(l1);

        Info l2;
        l2.row=0;
        l2.col=1;
        l2.blockType='L';
        c2->setInfo(l2);

        Info l3;
        l3.row=0;
        l3.col=2;
        l3.blockType='L';
        c3->setInfo(l3);

        Info l4;
        l4.row=1;
        l4.col=2;
        l4.blockType='L';
        c4->setInfo(l4);
    }

    else if(whichBlock=='J')
    {
        Info j1;
        j1.row=0;
        j1.col=0;
        j1.blockType='J';
        c1->setInfo(j1);

        Info j2;
        j2.row=0;
        j2.col=1;
        j2.blockType='J';
        c2->setInfo(j2);

        Info i3;
        i3.row=0;
        i3.col=2;
        i3.blockType='J';
        c3->setInfo(i3);

        Info j4;
        j4.row=1;
        j4.col=0;
        j4.blockType='J';
        c4->setInfo(j4);
    }
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

