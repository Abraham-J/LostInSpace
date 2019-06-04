# Author: Sanjo Abraham
#Description: Modular makefile 

#Project Name
PROJ = FinalProject_Abraham_Sanjo

SRC = main.cpp
SRC += Game.cpp
SRC += Space.cpp
SRC += Debris.cpp

OBJ = $(SRC:.c=.o)

output: $(OBJ) 
	g++ $(SRC)   -std=c++11 -o output

main.o: %.h main.cpp

clean: 
	rm *.o output
zip: 
	zip $(PROJ).zip *.cpp *.hpp makefile
