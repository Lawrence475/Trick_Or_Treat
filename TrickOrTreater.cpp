//Lawrence Wong 1001587603
//int TrickOrTreater= 0;
#include "House.h"
#include "TrickOrTreater.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <stdlib.h>
#include <map>

int TrickOrTreater::ImDone = 0;
TrickOrTreater::TrickOrTreater(std::string NEWname, std::vector<House*>NEWListOfHouses)
	: name{NEWname}, ListOfHouses{NEWListOfHouses}
{}
std::string TrickOrTreater::getName() //gets the name of the TrickOrTreater
{
	return name;
}
void TrickOrTreater::GoTrickOrTreating()
{
	for(auto it: ListOfHouses) //range based for loop to move the TOT along the houses
	{
		int CandyQuant;
		int speed = (rand()% 500) + 1; //random number to be generated for the speed	
		Walk(speed); //passing in the speed into the walk
		std::string CandyName;
		CandyName = it->ringDoorbell(path);  //candyname set to what ringdoorbell returns (a random candy name)
		Bucket[CandyName]++; //incrementing the value at the candy key
	}
	TrickOrTreater::ImDone++; //incrementing I'm done variable to notify that we're done with the house?
}
void TrickOrTreater::Walk(int Speed)
{
	int i;
	for(i = 0; i < 10; i++) //for loop to get through the distance between each house
	{
		this->path << ".";  //should add a dot to the ostringstream
		std::this_thread::sleep_for(std::chrono::milliseconds(Speed)); //sleeps the thread for however long speed is
	}
}
void TrickOrTreater::joinThread()
{
	this->TOTThreadPtr->join();
	delete this->TOTThreadPtr; //deletes the pointer for the thread when we're done joining it
}
void TrickOrTreater::startThread()
{
	TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);
}
std::string TrickOrTreater::getPath()
{
	return path.str();
}
std::ostream& operator<<(std::ostream& o, TrickOrTreater& TOTOBJ)
{
	std::map<std::string, int> NEWMAP = TOTOBJ.Bucket; //setting new map equal to the bucket
	for(auto it: NEWMAP) //range based for loop to make sure the overloaded operator prints out everything from the bucket
	{
		o << it.second << " " << it.first << ",";
	}
	return o;
}
