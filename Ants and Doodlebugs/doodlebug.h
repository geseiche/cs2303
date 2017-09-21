// Grace Seiche - PA6
// doodlebug.h

#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "organism.h"
#include "board.h"

class Doodlebug : public Organism {

public:
	Doodlebug(int x, int y);
	virtual ~Doodlebug();
	std::vector<int> antSpaces (Board& board);
	virtual void move (Board& board);
	virtual bool breedEligible();
	virtual void breed (Board& board);
	void checkStarvation ();

private:
	int stepsSinceEat;

};

#endif
