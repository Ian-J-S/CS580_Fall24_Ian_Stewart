# Ian Stewart
# Makefile for Assignment 2
# CSCI 580 - Artificial Intelligence
# CSU Chico, Fall 2024

CFLAGS = -o 
SRC = approxPi.cpp
EXE = approxPi

.PHONY:
	clean
	debug

$(EXE) : $(SRC)
	g++ $(SRC) $(CFLAGS) $(EXE)

clean:
	rm -rf $(EXE)

debug:
	g++ $(SRC) -g $(CFLAGS) $(EXE)