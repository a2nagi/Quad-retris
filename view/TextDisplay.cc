#include "TextDisplay.h"
#include "../controller/Block.h"

using namespace std;

TextDisplay::TextDisplay(Grid *g) : theGrid(g)
{
	rowLimit = g->getRows();
	colLimit = g->getColumns();

	for(int i=0;i<rowLimit;i++)
	{
		vector <char> row;
		for(int j=0;j<colLimit;j++)
		{
		    row.emplace_back(' ');
		}
		theDisplay.emplace_back(row);
	}
}

void TextDisplay::notify(Subject &whoNotified)
{
 	Info I = whoNotified.getInfo();
 	theDisplay[I.row][I.col]=I.blockType;
}

ostream &operator<<(std::ostream &out, const TextDisplay &td)
{
	//Todo
    out << "Level:     " << td.theGrid->getLevel() << endl;
    out << "Score:     " << td.theGrid->getScore() << endl;
    out << "Hi Score:  " << td.theGrid->getHighScore() << endl;

	for(int t=0;t<td.colLimit;t++){
		out<<"-";
	}
	out<<endl;
	for(int i=td.rowLimit-1;i>=0;i--){
		for(int j=0;j<td.colLimit;j++){
			out<<td.theDisplay.at(i).at(j);
		}
	out<<endl;
	}

	for(int b=0;b<td.colLimit;b++){
		out<<"-";
	}
	out<<endl;

	out<<"Next:"<<endl;
	if(td.theGrid->getNextBlock() != nullptr) {
		out << td.theGrid->getNextBlock()->toString() << endl;
	}

	//out<<NEXT BLOCK;
  return out;
}
