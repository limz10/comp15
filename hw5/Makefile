#
# Makefile for SongSearch, Assignment 5
#
CXX = g++
FLAGS = -Wall -Wextra -Wconversion -g -std=gnu++11

songsearch: main.cpp song.h song.cpp database.h database.cpp

	${CXX} ${FLAGS} -o songsearch main.cpp song.cpp database.cpp


clean:
	rm -f songsearch

provide_design:
	provide comp15 hw5_design songsearch_design.txt

provide:
	provide comp15 hw5 main.cpp song.h song.cpp database.h database.cpp \
				Makefile README.txt


