#
# Makefile for Sorts, Assignment 4
#
CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -g

all: SelectionSort.cpp SelectionSort.h main1.cpp \
     quickSort.cpp quickSort.h main2.cpp \
     mergeSort.cpp mergeSort.h main3.cpp
	${CXX} ${FLAGS} -o selectionSort SelectionSort.cpp main1.cpp
	${CXX} ${FLAGS} -o quickSort quickSort.cpp main2.cpp
	${CXX} ${FLAGS} -o mergeSort mergeSort.cpp main3.cpp

selectionSort: SelectionSort.cpp SelectionSort.h main1.cpp
	${CXX} ${FLAGS} -o selectionSort SelectionSort.cpp main1.cpp

quickSort: quickSort.cpp quickSort.h main2.cpp
	${CXX} ${FLAGS} -o quickSort quickSort.cpp main2.cpp

mergeSort: mergeSort.cpp mergeSort.h main3.cpp
	${CXX} ${FLAGS} -o mergeSort mergeSort.cpp main3.cpp

clean:
	rm -f selectionSort quickSort sort3

make provide:
	provide comp15 hw4 main1.cpp SelectionSort.cpp SelectionSort.h \
	        main2.cpp quickSort.cpp quickSort.h \
	        main3.cpp mergeSort.cpp mergeSort.h \
	        readme.txt Makefile

