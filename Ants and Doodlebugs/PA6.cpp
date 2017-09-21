// Grace Seiche - PA6
// PA6.cpp

#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "organism.h"
#include "board.h"
#include "ant.h"
#include "doodlebug.h"

int gridSize;
int numDoodlebugs;
int numAnts;
int timeSteps;
int pause;
int doodlebugOffspring;
int antOffspring;
std::ofstream outStream;
std::vector<Organism*> allOrganisms;
std::vector<Organism*> stepOffspring;

void initializeCommands(int argc, char *argv[]){
	//intialize variables to default values
	gridSize = 20;
	numDoodlebugs = 5;
	numAnts = 100;
	timeSteps = 1000;
	pause = 0;
	doodlebugOffspring=0;
	//initialize commandline arguments
	if(argc>=2){
		gridSize = std::atoi(argv[1]);
		if(argc>=3){
			numDoodlebugs = std::atoi(argv[2]);
			if(argc>=4){
				numAnts = std::atoi(argv[3]);
				if(argc>=5){
					timeSteps = std::atoi(argv[4]);
					if(argc>=6){
						srand(std::atoi(argv[5]));
						if(argc>=7){
							pause = atoi(argv[6]);
						}
					}
				}
			}
		}
	}
}

void moveAndBreedDoodlebugs (Board& board){
	for(unsigned int i=0; i<allOrganisms.size(); i++){
		if(allOrganisms[i]->getType()==DOODLEBUG){
			allOrganisms[i]->move(board);
			((Doodlebug*)allOrganisms[i])->checkStarvation();
			if(allOrganisms[i]->breedEligible()){
				allOrganisms[i]->breed(board);
			}
		}
	}
}

void removeDead(Board& board){
	for(unsigned int i=0; i<allOrganisms.size(); i++){
		if(allOrganisms[i]->isDead()){
			if(allOrganisms[i]->getType()==DOODLEBUG){
				board.grid[allOrganisms[i]->getRowPos()][allOrganisms[i]->getColPos()] = 0;
			}
			allOrganisms.erase(allOrganisms.begin()+i);
			i--;
		}
	}
}

void moveAndBreedAnts (Board& board){
	for (unsigned int i = 0; i<allOrganisms.size(); i++){
		if(allOrganisms[i]->getType()==ANT){
			allOrganisms[i]->move(board);
			if(allOrganisms[i]->breedEligible()){
				allOrganisms[i]->breed(board);
			}
		}
	}
}

void combineVectors(){
	if(!stepOffspring.empty()){
		for(unsigned int i=0; i<stepOffspring.size(); i++){
			allOrganisms.push_back(stepOffspring[i]);
		}
		stepOffspring.clear();
	}
}

bool checkTermination (Board& board){
	return (board.countAnts()==0 || board.countDoodlebugs()==0);
}

void printStats (int argc, char *argv[], Board& board, std::ofstream& outStream, int steps){
	if (pause==0 || steps%pause!=0){
		outStream << "Step " << steps << ":\n";
		board.printBoard(outStream);
	}
	for(int i = 0; i<argc; i++){
		outStream << argv[i] << ' ';
	}
	outStream << std::endl;
	outStream << "Steps simulated: " << (steps +1) << std::endl;
	outStream << "Total ants with births: " << (numAnts + antOffspring) << std::endl;
	outStream << "Total doodlebugs with births: " << (numDoodlebugs + doodlebugOffspring) << std::endl;
	outStream << "Terminating ants: " << board.countAnts() << std::endl;
	outStream << "Terminating doodlebugs: " << board.countDoodlebugs() << std::endl;
}

int main (int argc, char *argv[]){
	outStream.open("output.txt");
	initializeCommands(argc, argv);
	if(gridSize <= 0){
		outStream << "invalid grid argument" << std::endl;
		return 1;
	} else if (numAnts <=0){
		outStream << "invalid ants argument" << std::endl;
		return 1;
	} else if (numDoodlebugs <=0){
		outStream << "invalid doodlebugs argument" << std::endl;
		return 1;
	} else if (timeSteps <=0){
		outStream << "invalid timeSteps argument" << std::endl;
		return 1;
	} else if (pause <0){
		outStream << "invalid pause argument" << std::endl;
		return 1;
	}
	int step = 0;
	Board board (gridSize, numDoodlebugs, numAnts);
	outStream << "Step " << step << ":\n";
	board.printBoard(outStream);

	for (; step<timeSteps;step++){
		moveAndBreedDoodlebugs (board);
		removeDead(board);
		moveAndBreedAnts (board);
		combineVectors();
		if(pause != 0 && (step+1)%pause ==0){
			outStream << "Step " << (step+1) << ":\n";
			board.printBoard(outStream);
		}
		if(checkTermination(board)){
			break;
		}
	}

	printStats (argc, argv, board, outStream, step);
	outStream.close();
	return 1;
}
