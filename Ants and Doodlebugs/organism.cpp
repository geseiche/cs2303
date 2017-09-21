// Grace Seiche - PA6
// organism.cpp

#include <vector>
#include <cstdlib>
#include "organism.h"
#include "board.h"
using namespace std;

Organism::Organism(int xpos, int ypos){
	stepsSinceBreed=0;
	typeOfOrganism=ORGANISM;
	row=xpos;
	col=ypos;
	isLiving = true;
}

Organism::~Organism(){

}

std::vector<int> Organism::openSpaces(Board& board){
	std::vector<int> open;
	if( (row!=0) && !(board.grid[row-1][col])){//up
		open.push_back(UP);
	}
	if((col<(board.size-1)) && (board.grid[row][col+1]==0)){//right
		open.push_back(RIGHT);
	}
	if(row<(board.size-1) && !board.grid[row+1][col]){//down
		open.push_back(DOWN);
	}
	if( (col!=0) && !board.grid[row][col-1]){//left
		open.push_back(LEFT);
	}
	return open;
}

int Organism::randomSpace (int size){
	if (size<=0){
		return -1;
	}
	int loc = rand();
	loc = (int)(size*(loc/((float) RAND_MAX)));
	return loc;
}

int Organism::getType(){
	return this->typeOfOrganism;
}

void Organism::setPosition(int x, int y){
	this->row = x;
	this->col = y;
}

int Organism::getRowPos(){
	return row;
}

int Organism::getColPos(){
	return col;
}

void Organism::makeDead(){
	isLiving = false;
}

bool Organism::isDead(){
	return !isLiving;
}
