//Lawrence Wong 1001587603

#include "House.h"
#include <iostream>
#include <sstream>


#ifndef _TOOTHBRUSHHOUSE_H
#define _TOOTHBRUSHHOUSE_H
class ToothbrushHouse : public House //inheritaes from house
{
	public :
		ToothbrushHouse(std::string, std::map<int, std::string>);
		std::string ringDoorbell(std::ostringstream &);
		~ToothbrushHouse();
};

#endif