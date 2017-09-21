// Grace Seiche - PA6
// ant.cpp

#include "ant.h"
#include "organism.h"
#include "board.h"

extern int antOffspring;
extern std::vector<Organism*> stepOffspring;

Ant::Ant(int x, int y) : Organism(x, y){
	Organism::typeOfOrganism = ANT;
}

Ant::~Ant() {

}

void Ant::move(Board& board){
	stepsSinceBreed++;
	std::vector<int> open = this->openSpaces(board);
	int loc = this->randomSpace(open.size());
	if (loc==-1){
		return;
	}
	switch (open[loc]){
	case UP:
		board.grid[row-1][col] = this;
		board.grid[row][col] = 0;
		row--;
		break;
	case LEFT:
		board.grid[row][col-1] = this;
		board.grid[row][col] = 0;
		col--;
		break;
	case DOWN:
		board.grid[row+1][col] = this;
		board.grid[row][col] = 0;
		row++;
		break;
	case RIGHT:
		board.grid[row][col+1] = this;
		board.grid[row][col] = 0;
		col++;
		break;
	}
	return;
}

bool Ant::breedEligible(){
	return (this->stepsSinceBreed >= 3 && this->isLiving);
}

void Ant::breed(Board& board){
	std::vector<int> open = this->openSpaces(board);
	int loc = this->randomSpace(open.size());
	if(loc==-1){
		return;
	}
	Organism *p;
	switch (open[loc]){
	case UP:
		p = new Ant(row-1, col);
		board.grid[row-1][col] = p;
		stepOffspring.push_back(p);
		break;
	case LEFT:
		p = new Ant(row, col-1);
		board.grid[row][col-1] = p;
		stepOffspring.push_back(p);
		break;
	case DOWN:
		p = new Ant(row+1, col);
		board.grid[row+1][col] = p;
		stepOffspring.push_back(p);
		break;
	case RIGHT:
		p = new Ant(row, col+1);
		board.grid[row][col+1] = p;
		stepOffspring.push_back(p);
		break;
	}
	antOffspring++;
	this->stepsSinceBreed = 0;
}
