#include "TextDisplay.h"

using namespace std;


TextDisplay::TextDisplay(Grid *g){
	int rowLimit=18;
	int colLimit=11;
	for(int i=0;i<rowLimit;i++){
		vector <char> row;
		for(int j=0;j<colLimit;j++){
			row.emplace_back(' ');
		}
	}
TextDisplay::TextDisplay(Grid *g)
{
	theGrid=g;
	int rowLimit=18;
	int colLimit=11;
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

TextDisplay::notify(subject &whoNotified)
{
 	Info I=whoNotified.getInfo();
 	theDisplay[I.r][I.c]=I.blockType;
}

ostream &operator<<(std::ostream &out, const TextDisplay &td)
{
	out<<"Level:"<<"      "<<g.getLevel()<<endl;//Not sure if these correlate to the actual funtions, but shouldnt be a task
	out<<"Score:"<<"      "<<g.getScore()<<endl;
	out<<"Hi Score:"<<"  "<<g.getHiScore()<<endl;
	
	int rowLimit=18;
	int colLimit=11
	for(int t=0;t<colLimit;t++){
		out<<"-";
	}
	out<<endl;
	for(int i=0;i<rowLimit;i++){
		for(int j=0;j<colLimit;j++){
			out<<theDisplay[i][j];
		}
	out<<endl;
	}

	for(int b=0;b<colLimit;b++){
		out<<"-";
	}
	out<<endl;

	out<<"Next:"<<endl;
	//out<<NEXT BLOCK;
	return out;	
}
