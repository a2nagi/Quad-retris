//
// Created by Harkamal on 2017-11-24.
//

#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include "../Model/Observer.h"
#include "../Model/Subject.h"
#include "Grid.h"

Class Cell;

class TextDisplay:public Observer{
	Grid theGrid;
	std::vector<std::vector<char>> theDisplay;
public:
	TextDisplay();
	void notify(subject &whoNotified) override;
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};


#endif //CS246_PROJECT_TEXTDISPLAY_H
