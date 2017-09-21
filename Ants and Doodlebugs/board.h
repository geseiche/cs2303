// Grace Seiche - PA6
// board.h

#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include "organism.h"

class Organism;

class Board {

public:
	Board(int size, int numDoodle, int numAnts);
	~Board();
	Organism ***grid;
	int size;
	void printBoard(std::ofstream& outStream);
	int countAnts ();
	int countDoodlebugs();


private:

};

#endif
