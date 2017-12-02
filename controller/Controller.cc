#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <fstream>
#include "Block.h"
#include "Level.h"
#include "../model/Grid.h"
#include "Controller.h"
#include "../view/TextDisplay.h"

using namespace std;

Controller::Controller(Grid *g,TextDisplay *td): g{g},td{td} {
    cout << *td;
};

void Controller::parseCommand(){


    string s;
    bool match;
    int multiple=1;

    //The commands in Regular Expression
    regex left("lef");
    regex right("ri");
    regex down("do");
    regex clockwise("cl");
    regex counterclockwise("co");
    regex drop("dr");
	regex levelup("levelu");
 	regex leveldown("leveld");
 	regex norandom("nor");
 	regex random("ra");
// 	regex sequence(".s.*");//Sarthak
// 	regex blocks(".[IJLOSZT]");//Sarthak
// 	regex restart(".re.*");//Sarthak
// 	regex hint(".h*");//Harkamal

    while(getline(cin, s)){
        if(isdigit(s[0])) {
            multiple = stoi(s);
        }
        else {
            multiple = 1;
        }

        if(regex_search(s,left)){
            g->moveCurrentBlockLeftRight(Direction::left, multiple);
            cout<<*td;
        }

        else if(regex_search(s,right)){
            g->moveCurrentBlockLeftRight(Direction::right, multiple);
            cout<<*td;
        }

        else if(regex_search(s,down)){
            g->moveCurrentBlockDown(multiple);
            cout<<*td;
        }

        else if(regex_search(s,clockwise)){
            multiple = multiple%4;
            g->rotateBlock(Rotate::clockWise, multiple);
            cout<<*td;
        }

        else if(regex_search(s,counterclockwise)){
            multiple = multiple%4;
            g->rotateBlock(Rotate::counterClockWise, multiple);
            cout<<*td;
        }

        else if(regex_search(s,drop)){
            for(int i = 0; i < multiple; i++) {
                g->dropBlock();
            }
            cout<<*td;
        }

        else if(regex_search(s,levelup)){
			g->nextLevel(multiple);
		}

		else if(regex_search(s,leveldown)){
            g->levelDown(multiple);
		}

        else if(regex_search(s,norandom)){
            istringstream textStream{s};
            string fileName;
            textStream >> fileName;
            textStream >> fileName;
        }
//			string filename;
//			ifstream f;
//			f.open(filename);
//			char c;
//			while(f>>c){
//
//			}
//
//		}
//
//		else if(regex_match(s,random)){
//
//		}
        else {
            throw "Command not supported";
        }


//
//
//
//		else if(regex_match(s,sequence)){//Applicable to level
//			string filename;
//			ifstream f;
//			f.open(filename);
//			char c;
//			while(f>>c){
//				currLevel->getNextBlock(c);
//			}
//		}
//
//		else if(regex_match(s,blocks)){
//			currLevel->getNextBlock(s);
//		}
//
//		else if(regex_match(s,restart)){
//
//		}
//
//		else if(regex_match(s,hint)){
//
//		}


    }
}

