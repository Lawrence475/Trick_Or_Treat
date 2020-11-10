//Lawrence Wong 1001587603
#include "CandyHouse.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <stdlib.h>
#include <map>

CandyHouse::CandyHouse(std::string HOUSEname, std::map<int,std::string>CandyRM)
	: House(HOUSEname, CandyRM)
{}
std::string CandyHouse::ringDoorbell(std::ostringstream &PATH)
{
	door.lock(); //locks the mutex
	int CandyNUM;
	std::string CandyName;
	PATH << "+";//adds an * to the ostringstream
	std::this_thread::sleep_for(std::chrono::milliseconds(3));
	CandyNUM = (rand()% CandyRankingMap.size()) + 1; //generates random number from the 
	CandyName = CandyRankingMap[CandyNUM]; //setting the name of the candy equal to the name that was picked 
	door.unlock(); //unlocks the thread
	return CandyName; //returns the candy name
}
CandyHouse::~CandyHouse()
{
	std::cout << "CandyHouse\n";
	//House::~House;
}
