// Grace Seiche - PA6
// organism.h

#ifndef ORGANISM_H
#define ORGANISM_H

#include <vector>
#include "board.h"

enum Type {ANT, ORGANISM, DOODLEBUG};
enum Direction {UP, DOWN, LEFT, RIGHT};

class Board;

class Organism {

public:
	Organism(int xpos, int ypos);
	virtual ~Organism();
	virtual void move (Board& board)=0;
	virtual bool breedEligible()=0;
	virtual void breed (Board& board)=0;
	std::vector<int> openSpaces(Board& board);
	int randomSpace (int size);
	int getType();
	void setPosition(int x, int y);
	int getRowPos();
	int getColPos();
	void makeDead();
	bool isDead();

protected:
	int stepsSinceBreed;
	int typeOfOrganism;
	int row;
	int col;
	bool isLiving;

};

#endif
