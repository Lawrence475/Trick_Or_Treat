//Lawrence Wong 1001587603
#include "House.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <stdlib.h>
#include <map>

House::House(std::string HOUSEname, std::map<int,std::string>CandyRM)
	: houseName{HOUSEname}, CandyRankingMap{CandyRM}
{}
std::string House::ringDoorbell(std::ostringstream &PATH)
{}
House::~House()
{
	std::cout << "House" << std::endl;
}
