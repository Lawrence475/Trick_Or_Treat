//Lawrence Wong 1001587603
#include "House.h"
#include <iostream>
#include <sstream>


#ifndef _CANDYHOUSE_H
#define _CANDYHOUSE_H
class CandyHouse : public House //inheritaes from House
{
	public :
		CandyHouse(std::string, std::map<int, std::string>);
		std::string ringDoorbell(std::ostringstream &);
		~CandyHouse();
};

#endif
