
#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include "../model/Observer.h"
#include "../model/Subject.h"
#include "../model/Grid.h"
#include "../model/Info.h"

class Cell;

class TextDisplay:public Observer{
	Grid *theGrid;
	int colLimit;
	int rowLimit;
	std::vector<std::vector<char>> theDisplay;
public:
	TextDisplay(Grid *g);
	void notify(Subject &whoNotified) override;
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};


#endif //CS246_PROJECT_TEXTDISPLAY_H
