// House class header file
//Lawrence Wong 1001587603

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>

#ifndef _HOUSE_H
#define _HOUSE_H

class House
{
	public :
		House(std::string, std::map<int, std::string>);
		//making the functin virtual so that we can overide the function
		virtual std::string ringDoorbell(std::ostringstream &) = 0;
		virtual ~House() = 0; //destructor for the class

	protected : //protected to make the derived classes to be able to inherit and use the member functions
		std::string houseName;
		std::mutex door;
		std::map<int,std::string>CandyRankingMap;
};

#endif	