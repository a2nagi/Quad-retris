#include "TextDisplay.h"

using namespace std;

<<<<<<< HEAD
TextDisplay::TextDisplay(Grid *g){
	int rowLimit=18;
	int colLimit=11;
	for(int i=0;i<rowLimit;i++){
		vector <char> row;
		for(int j=0;j<colLimit;j++){
			row.emplace_back(' ');
		}
=======
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
		
>>>>>>> 38181108d106df1d8bd4e008a9bc23b601962b91
		theDisplay.emplace_back(row);
	}
}

<<<<<<< HEAD
TextDisplay::notify(subject &whoNotified){
=======
TextDisplay::notify(subject &whoNotified)
{
>>>>>>> 38181108d106df1d8bd4e008a9bc23b601962b91
 	Info I=whoNotified.getInfo();
 	theDisplay[I.r][I.c]=I.blockType;

}


<<<<<<< HEAD
ostream &operator<<(std::ostream &out, const TextDisplay &td){
	out<<"Level:"<<"      "<<g.getLevel()<<endl;
=======
ostream &operator<<(std::ostream &out, const TextDisplay &td)
{
	out<<"Level:"<<"      "<<g.getLevel()<<endl;//Not sure if these correlate to the actual funtions, but shouldnt be a task
>>>>>>> 38181108d106df1d8bd4e008a9bc23b601962b91
	out<<"Score:"<<"      "<<g.getScore()<<endl;
	out<<"Hi Score:"<<"  "<<g.getHiScore()<<endl;
	
	int rowLimit=18;
	int colLimit=11
<<<<<<< HEAD
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
=======
	for(int t=0;t<colLimit;t++)
	{
		out<<"-";
	}
	out<<endl;
	for(int i=0;i<rowLimit;i++)
	{
	     for(int j=0;j<colLimit;j++)
	     {
		 out<<theDisplay[i][j];
	     }
	     out<<endl;
	}

	for(int b=0;b<colLimit;b++)
	{
		out<<"-";
	}
	out<<endl;
        out<<"Next:"<<endl;
	//out<<NEXT BLOCK;//Have to add Next Block Function
	return out;	
}
>>>>>>> 38181108d106df1d8bd4e008a9bc23b601962b91
