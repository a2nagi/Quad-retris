
#include <iostream>
#include "model/Cell.h"
#include "model/Grid.h"
#include "view/TextDisplay.h"
#include "controller/Controller.h"
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

    // 1st Argument=argv[1];
    bool isOnlyText = false;
    int i = 1;
    int seed = time(nullptr);
    string fileName = "sequence.txt";
    int startLevel = 0;
    while (i < argc) {
        if(strcmp(argv[i], "-text") == 0) {
            isOnlyText = true;
        }
        else if (strcmp(argv[i], "-seed") == 0) {
            i++;
            if(i == argc) {
                exit(1);
            }
            seed = stoi(argv[i]);
        }
        else if( strcmp(argv[i], "-scriptfile") == 0 ){
            i++;
            if(i == argc) {
                exit(1);
            }
            fileName = argv[i];
        }
        else if( strcmp(argv[i],"-startlevel") == 0 ) {
            i++;
            if(i == argc) {
                exit(1);
            }
            fileName = argv[i];
        }
        i++;
    }
    //Set seed
    srand(seed);
    Grid g;
    isOnlyText = true;
    g.initGrid(fileName, startLevel, isOnlyText);
    TextDisplay *td = g.getTextDisplay();
    Controller c(&g, td);
    c.parseCommand(&cin);
}

