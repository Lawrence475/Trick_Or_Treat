//Lawrence Wong 1001587603
#include "House.h"
#include "TrickOrTreater.h"
#include "CandyHouse.h"
#include "ToothbrushHouse.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <string.h>
#include <thread>
#include <new>
#include <iomanip>
#include <thread>
#include <ctime>

using namespace std;

void get_command_line_params(int Command1, char *Command2[], string &TOT, string &Houses, string &Candy) //function to get command line parameter
{
	if(Command1 == 4)//if we have less than four command line parameters
	{
		TOT = Command2[Command1-3]; //setting strings equal to the parameters passed in
		Houses = Command2[Command1-2];
		Candy = Command2[Command1-1];
	}
	else //there wasn't enough paramters passed in
	{
		throw invalid_argument("Missing command line paratmeters - - Usage : input filename output filename"); //throws exception for the catch?
	}
}
int main(int argc, char *argv[]) //command line parameters
{
	srand((int)time(0));
	vector<string>TokenCandyName;
	vector<int>TokenCandyRank;
	string TOT, Houses, Candy, TempString; //string variables to hold the file names
	try //throwing exception if there isn't any files that are provided
	{
		get_command_line_params(argc, argv, TOT, Houses, Candy); //calling the function to get the proper command line parameters
	}
	catch(invalid_argument& say) //catch to make sure not have the error end the program
	{
		cout << say.what() << endl; //catching the exception that is thrown
		exit(0); //exits program when there aren't enough paramters
	}
	ifstream CandyFILE{Candy}; //opening the files
	ifstream HouseFILE{Houses};
	ifstream TOTFILE{TOT};
	int i;
	if(CandyFILE.is_open()) //while the candy file is open
	{
		int counter = 0;
		int wow = 0;
		while(getline(CandyFILE, TempString)) //while loop to get each line of the file
		{
			char str[100]; //character array
			char *token; //character pointer
			for(i = 0; i < TempString.size(); i++) //for loop to go through the entire string that we got from the file
			{
				str[i] = TempString.at(i); //will take the individual letters and put it into the character arrays
			}
			token = strtok(str,"|,\0"); //using the strtok to seperate the string by the |
			TokenCandyName.push_back(token); // pushing the string into the vector
			int work = 0; //some value to help reduce
			while(token != NULL) //while the pointer is not NULL, meaning it hasn't gotten to the end of the string execute
			{
				if(work == 1) //if work hasn't incremented yet then do this
				{
					TokenCandyRank.push_back(atoi(token)); //adds the number into the vector 
				}
				token = strtok(NULL,"|,\0"); //it starts again after the delimiter
				work++; //increments the work
			}
		}
	}
	CandyFILE.close();
	map<int, string>CandyRank; //making map for the candy rank, int is the key values, and string is the key's associated value is a string
	
	for(i = 0; i < TokenCandyName.size(); i++) //for loop to insert everything
	{
		CandyRank.insert(make_pair(TokenCandyRank.at(i),TokenCandyName.at(i)));
	}
	ostringstream HouseHeader;
	vector<House*> HousePointers; //making a vector full of pointers to house
	if(HouseFILE.is_open()) //checks if the house file is open
	{
		
		string HouseNames;
		int Align = 0;
		HouseHeader << setw(10) << "     ";//setting the space for the first line of the 
		while(getline(HouseFILE, HouseNames)) //getting lines
		{
			if(Align == 0) //if it's the first iteration then we have to align it to ten spaces
			{
				HouseHeader << left << setw(10) << HouseNames; //putting house names into ostringstream
				Align++;
			}
			else
			{
				HouseHeader << left << setw(11) << HouseNames; //otherwise we'll have space for the houses
			}
			int HouseType = (rand()% 2 + 1); //will pick a random number from 0 and 1
			if(HouseType == 1) //if it's one it will be candy house
			{
				HousePointers.push_back(new CandyHouse(HouseNames, CandyRank)); //new to make space for house object and so that we're not copying the object
			}
			else//otherwise it will be a toothbrush house
			{
				HousePointers.push_back(new ToothbrushHouse(HouseNames, CandyRank)); //new to make space for house object and so that we're not copying the object
			}
		}
		cout << endl;
	}
	HouseFILE.close(); //this is to close the file
	//STEP 9 IS HERE
	string TempNames; //making a temporary string to save the lines from the file to
	vector<TrickOrTreater>VECTORTOT; //vector for the TOT names
	if(TOTFILE.is_open()) //if the file is open then execute
	{
		while(getline(TOTFILE, TempNames)) //getline will grab all the lines in the file
		{
			VECTORTOT.push_back(TrickOrTreater{TempNames, HousePointers}); //pushing back the names
		}
	}
	TOTFILE.close(); //closing the file
	for(auto &it: VECTORTOT) // range based loop to start the thread
	{
		it.startThread();
	}
	while(TrickOrTreater::ImDone != VECTORTOT.size()) //while loop to continue printing the new output when people aren't done yet
	{
		cout << HouseHeader.str() << endl;
		for(auto &it: VECTORTOT) //range based for loop to printout the updated paths and their names
		{
			cout << it.getPath() << it.getName() << endl;
		}
		this_thread::sleep_for(chrono::milliseconds(5)); //sleeps the main thread for 5 milliseconds
		for(i = 0; i < 34; i++) //for loop to clear the screen 
		{
			cout << endl; 
		}
	}
	TrickOrTreater TEMPTOT(TempNames, HousePointers); //creating an object to pass into the overloaded operator for it to work
	for(auto &it: VECTORTOT) //range based for loop to go through all the kids
	{
		cout << it.getName() << "'s - " << it << endl;
	}
	for(auto &it: VECTORTOT) // range based loop to join the threads
	{
		it.joinThread();
	}
	for(auto &it: HousePointers)
	{
		delete it; //when it's deleted the destructor will be called 
	}
}
