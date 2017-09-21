// Grace Seiche - PA6
// ant.h

#ifndef ANT_H
#define ANT_H

#include "organism.h"
#include "board.h"

class Ant : public Organism {

public:
	Ant(int x, int y);
	virtual ~Ant();
	virtual void move (Board& board);
	virtual bool breedEligible();
	virtual void breed (Board& board);

private:

};

#endif
