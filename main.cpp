
#include <iostream>
#include "model/Cell.h"
#include "model/Grid.h"
#include "view/TextDisplay.h"
#include "controller/Controller.h"
#include <sstream>
#include <cstdlib>
#include <process.h>

using namespace std;

int main(int argc, char *argv[]) {

    // 1st Argument=argv[1];
    bool isOnlyText = false;
    int i = 0;
    int seed = getpid();
    string fileName = "sequence.txt";
    int startLevel = 0;
    while (i < argc) {
        if(argv[i] == "-text") {
            isOnlyText = true;
        }
        else if (argv[i] == "-seed") {
            i++;
            if(i == argc) {
                exit(1);
            }
            seed = stoi(argv[i]);
        }
        else if(argv[i] == "-scriptfile"){
            i++;
            if(i == argc) {
                exit(1);
            }
            fileName = argv[i];
        }
        else if(argv[i] == "-startlevel") {
            i++;
            if(i == argc) {
                exit(1);
            }
            fileName = argv[i];
        }
        i++;
    }

    Grid g;
    g.initGrid();
    TextDisplay *td = g.getTextDisplay();
    Controller c(&g, td);
    c.parseCommand();
}

