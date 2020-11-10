//Lawrence Wong 1001587603
#include "ToothbrushHouse.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <stdlib.h>
#include <map>

ToothbrushHouse::ToothbrushHouse(std::string HOUSEname, std::map<int,std::string>CandyRM)
	: House(HOUSEname, CandyRM)
{}
std::string ToothbrushHouse::ringDoorbell(std::ostringstream &PATH)
{
	door.lock(); //locks the mutex
	std::string CandyName;
	PATH << "-";//adds an * to the ostringstream
	std::this_thread::sleep_for(std::chrono::milliseconds(3));
	CandyName = "TOOTHBRUSH"; //setting the name of the candy equal to the name that was picked 
	door.unlock(); //unlocks the thread
	return CandyName; //returns the candy name
}
ToothbrushHouse::~ToothbrushHouse()
{
	std::cout << "ToothbrushHouse\n";
}
