// Grace Seiche - PA6
// board.cpp

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include "board.h"
#include "organism.h"
#include "doodlebug.h"
#include "ant.h"

extern std::vector<Organism*> allOrganisms;

Board::Board (int size, int numDoodle, int numAnts){
	this->size = size;
	grid =  new Organism** [size];
	for(int i=0; i<size; i++){
		grid[i] = new Organism* [size];
	}
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			grid[i][j] = 0;
		}
	}
	for (int i=0; i<numDoodle; i++){
		int j = size*(rand()/float(RAND_MAX));
		int k = size*(rand()/float(RAND_MAX));
		if(grid[j][k]==0){
			Organism *p = new Doodlebug (j, k);
			grid[j][k] = p;
			allOrganisms.push_back(p);
		} else {
			i--;
		}
	}
	for (int i=0; i<numAnts; i++){
		int j = size*(rand()/float(RAND_MAX));
		int k = size*(rand()/float(RAND_MAX));
		if(grid[j][k]==0){
			Organism *p = new Ant (j, k);
			grid[j][k] = p;
			allOrganisms.push_back(p);
		} else {
			i--;
		}
	}
}


Board::~Board(){
	for(int i=0; i<size; i++){
		delete [] grid[i];
	}
	delete [] grid;
}

void Board::printBoard(std::ofstream& outStream){
	for(int row=0; row<this->size; row++){
		for(int col=0; col<this->size; col++){
			if(this->grid[row][col]==0){
				outStream << std::setw(2) << ' ';
			} else if (this->grid[row][col]->getType()==ANT){
				outStream << std::setw(2) << 'o';
			} else {
				outStream << std::setw(2) << 'x';
			}
		}
		outStream << std::endl;
	}
	for(int i=0; i<size; i++){
		outStream << std::setw(2) << "--";
	}
	outStream << "-" << std::endl;
}

int Board::countAnts(){
	int totalAnts = 0;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if (grid[i][j] !=0 && grid[i][j]->getType() ==ANT){
				totalAnts++;
			}
		}
	}
	return totalAnts;
}

int Board::countDoodlebugs(){
	int totalDoodlebugs = 0;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if (grid[i][j] != 0 && grid[i][j]->getType() ==DOODLEBUG){
				totalDoodlebugs++;
			}
		}
	}
	return totalDoodlebugs;
}
