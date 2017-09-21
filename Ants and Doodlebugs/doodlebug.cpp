// Grace Seiche - PA6
// doodlebug.cpp

#include "doodlebug.h"
#include "organism.h"
#include "board.h"

extern int doodlebugOffspring;
extern std::vector<Organism*> stepOffspring;

Doodlebug::Doodlebug(int x, int y) : Organism(x, y){
	stepsSinceEat = 0;
	Organism::typeOfOrganism = DOODLEBUG;
}

Doodlebug::~Doodlebug() {

}

std::vector<int> Doodlebug::antSpaces(Board& board){
	std::vector<int> open;
	if( (row!=0) && board.grid[row-1][col]!=0 && board.grid[row-1][col]->getType()==ANT){//up
		open.push_back(UP);
	}
	if(col<(board.size-1) && board.grid[row][col+1]!=0  && board.grid[row][col+1]->getType()==ANT){//right
		open.push_back(RIGHT);
	}
	if(row<(board.size-1) && board.grid[row+1][col]!=0 && board.grid[row+1][col]->getType()==ANT){//down
		open.push_back(DOWN);
	}
	if( (col!=0) && board.grid[row][col-1]!=0 && board.grid[row][col-1]->getType()==ANT){//left
		open.push_back(LEFT);
	}
	return open;
}

void Doodlebug::move(Board& board){
	stepsSinceBreed++;
	std::vector<int> antSpaces = this->antSpaces(board);
	int loc = this->randomSpace(antSpaces.size());
	if (loc ==-1){
		this->stepsSinceEat++;
		std::vector<int> open = this->openSpaces(board);
		loc = this->randomSpace(open.size());
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
	} else{
		switch (antSpaces[loc]){
		case UP:
			board.grid[row-1][col]->makeDead();
			board.grid[row-1][col] = this;
			board.grid[row][col] = 0;
			row--;
			break;
		case LEFT:
			board.grid[row][col-1]->makeDead();
			board.grid[row][col-1] = this;
			board.grid[row][col] = 0;
			col--;
			break;
		case DOWN:
			board.grid[row+1][col]->makeDead();
			board.grid[row+1][col] = this;
			board.grid[row][col] = 0;
			row++;
			break;
		case RIGHT:
			board.grid[row][col+1]->makeDead();
			board.grid[row][col+1] = this;
			board.grid[row][col] = 0;
			col++;
			break;
		}
		this->stepsSinceEat =0;
	}
}

bool Doodlebug::breedEligible(){
	return (this->stepsSinceBreed >=8 && isLiving);
}

void Doodlebug::breed (Board& board){
	std::vector<int> open = this->openSpaces(board);
	int loc = this->randomSpace(open.size());
	if(loc==-1){
		return;
	}
	Organism *p;
	switch (open[loc]){
	case UP:
		p = new Doodlebug(row-1, col);
		board.grid[row-1][col] = p;
		stepOffspring.push_back(p);
		break;
	case LEFT:
		p = new Doodlebug(row, col-1);
		board.grid[row][col-1] = p;
		stepOffspring.push_back(p);
		break;
	case DOWN:
		p = new Doodlebug(row+1, col);
		board.grid[row+1][col] = p;
		stepOffspring.push_back(p);
		break;
	case RIGHT:
		p = new Doodlebug(row, col+1);
		board.grid[row][col+1] = p;
		stepOffspring.push_back(p);
		break;
	}
	doodlebugOffspring++;
	this->stepsSinceBreed = 0;
}

void Doodlebug::checkStarvation(){
	if(this->stepsSinceEat >=3){
		this->makeDead();
	}
}
