/*
    Author: Zaha Abbasi
    Date: 12/06/2025
    Description: This program uses a doubly linked list and c++ random generation to simulate 
				a train of cars traveling through stops. Cars have any type of the 4 types and can have a maximum of 5 stops.
				Cars are automatically inserted in sorted order, removed when their stops reach 0 and new cars are generated 
				randomly.
    Usage: compile the program using make command. execute the program using ./exe main.cpp
    The program uses the seed provided for random generation otherwise it uses the current time
*/
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "LinkedList.hpp"
#include "car.hpp"

typedef LinkedList<Car> CarList;
typedef Node<Car> CarNode;
// random number generator
std::mt19937_64 rng(time(nullptr));
// returns a seed from the environment variable SEED, if SEED not set , it returns the current time
long getSeed(){
	char* seedEnv = std::getenv("SEED");
	if (seedEnv){

		return std::atoi(seedEnv);

	}
	return time(nullptr);
}

// prints the entire train
void printTrain(CarList& train){
	CarNode* curr = train.getHeadNode();
	bool first = true;
	while(curr){
		const Car& c = curr->getData();
		if(!first){
			std::cout << "->";
			}
		std::cout << "[" << c.id << ":" << typeLetter(c.type) << ":" << c.stops << "]";
		first = false;
		curr = curr->getNext();
	}

	std::cout << "\n";
}

// insert a new car in the train ordered by type. Cars are sorted by increasing type number
void insertCar(CarList& train,const Car& c){
	CarNode* curr = train.getHeadNode();
	int index = 0;
	//find the corrrect sorted position
	while(curr && curr->getData().type <= c.type){
		
		curr = curr->getNext();
		index++;
	}

	

	train.insertAtIndex(c,index);
	std::cout << "Added car " << c.id << ": " << typeName(c.type) << " / " << c.stops << " stop(s)\n";

}

// remove any cars whose stop count has reached zero or below
void removeFinishedCars(CarList& train){
	CarNode* curr = train.getHeadNode();
	int index = 0;
	while(curr){
		if(curr->getData().stops <= 0 ){
			std::cout << "Removed car " << curr->getData().id << "\n";
			train.removeFromIndex(index);

			//restart scan because list changed
			curr = train.getHeadNode();
			index = 0;

		}
		else{
			curr = curr->getNext();
			index++;
		}
	}
}

//global ID counter
int nextCarID = 1;

//makes a random car with a random number of stops and a random type 
Car makeRandomCar(std::uniform_int_distribution<int>& stopsDist, std::uniform_int_distribution<int>& typeDist){
	
	int stops = stopsDist(rng);
	int type = typeDist(rng);
	return Car(nextCarID++,stops, type );
}

//Ensure there is atleast one Social car if there is at least one Passenger car
void checkAndAddSocial(CarList& train){
	bool hasPassenger = false, hasSocial =false;
	CarNode* c = train.getHeadNode();

	while(c){
		if(c->getData().type == 1){
			hasPassenger = true;
		}
		if(c->getData().type == 2){
			hasSocial = true;
		}
		c = c->getNext();
	}

    //add social car
	if(hasPassenger && !hasSocial){
		Car socialCar(nextCarID++, 1,2);
		insertCar(train, socialCar);
	}
}

int main(){
	rng.seed(getSeed());
	CarList train;

    //random distributions
	std::uniform_int_distribution<int> stopDist(1,5);
	std::uniform_int_distribution<int> typeDist(1,4);
	std::uniform_int_distribution<int> addDist(1,5);

     //create 10 intial cars
	for(int i=0;i<10;i++){
		insertCar(train, makeRandomCar(stopDist, typeDist));
	}

    //do 20 stops
	for(int stop =1;stop<=20;stop++){
		if(train.getSize()==0){
			break;
		}

		std::cout << "Arrived at stop " << stop << "\n";

		printTrain(train);
	
     //decrement stops for each car
	CarNode* curr = train.getHeadNode();

	while(curr){
		curr->getData().stops--;
		curr = curr->getNext();

	}
      //remove finished cars
	removeFinishedCars(train);

    //add random new cars
	int toAdd = addDist(rng);

	for(int i=0;i<toAdd;i++){
		insertCar(train, makeRandomCar(stopDist, typeDist));
	}

   //add social train if required
   checkAndAddSocial(train);

   std::cout << "Departed from stop " << stop << "\n";

   printTrain(train);

   }
   return 0;
}
