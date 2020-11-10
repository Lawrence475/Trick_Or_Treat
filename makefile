#makefile for C++ program
#Lawrence Wong 1001587603
SRC1 = Code6_1001587603.cpp
SRC2 = House.cpp
SRC3 = TrickOrTreater.cpp
SRC4 = CandyHouse.cpp
SRC5 = ToothbrushHouse.cpp

OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
OBJ4 = $(SRC4:.cpp=.o)
OBJ5 = $(SRC5:.cpp=.o)
EXE = $(SRC1:.cpp=.e)

HFILES = House.h TrickOrTreater.h CandyHouse.h ToothbrushHouse.h

GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

CFLAGS = -g -std=c++11 -pthread

all : $(EXE)
 
$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) -o $(EXE) $(GTKFLAGS)

$(OBJ1) : $(SRC1) $(HFILES)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1) $(GTKFLAGS)

$(OBJ2) : $(SRC2) $(HFILES)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2) $(GTKFLAGS)

$(OBJ3) : $(SRC3) $(HFILES)
	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3) $(GTKFLAGS)

$(OBJ4) : $(SRC4) $(HFILES)
	g++ -c $(CFLAGS) $(SRC4) -o $(OBJ4) $(GTKFLAGS)

$(OBJ5) : $(SRC5) $(HFILES)
	g++ -c $(CFLAGS) $(SRC5) -o $(OBJ5) $(GTKFLAGS)
