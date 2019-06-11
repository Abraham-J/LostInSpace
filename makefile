# Author: Sanjo Abraham
#Description: Modular makefile 

#Project Name
PROJ = FinalProject_Abraham_Sanjo

#SRC = main.cpp
#SRC += Game.cpp
#SRC += Space.cpp
#SRC += Debris.cpp
#SRC += Fog.cpp
#SRC += ./ItemFolder/Item.cpp
#SRC += slowRead.cpp
#SRC += Item.cpp
SRC += $(wildcard *.cpp) 
SRC += $(wildcard NonKeyItems/*.cpp)
SRC += $(wildcard KeyItems/*.cpp)

OBJ = $(SRC:.c=.o)
#Subsystem:
#	$(MAKE) -C Items
output: $(OBJ) 
	$(CXX) $(CXXFLAGS) $(SRC)   -std=c++11 -o output

main.o: %.h main.cpp

clean: 
	rm *.o output
zip: 
	zip $(PROJ).zip *.cpp *.hpp makefile
