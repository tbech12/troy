//Troy Bechtold
//2/5/2020
//CS 122
//Project 2

#ifndef LIBRARY_SORTING_H
#define LIBRARY_SORTING_H

//Librarys
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <chrono> 
using namespace std;
using namespace std::chrono;

//User Defined Functions
string fileName(string fileType, string sortType); //gets all file names for output
int randVectorNumbers(vector<int> numbers, int total, string oFileNameBubble, string oFileNameSelection, string oFileNameInsertion, string oFileNameShell); //creates a random vector of x numbers
int sortedVector(vector<int> numbers, int total, string oFileNameBubble, string oFileNameSelection, string oFileNameInsertion, string oFileNameShell); //creates a sorted vector of x numbers
int reversedSortedVector(vector<int> numbers, int total, string oFileNameBubble, string oFileNameSelection, string oFileNameInsertion, string oFileNameShell); //creates a reversed sorted vector of x numbers
int bubbleSort(vector<int> numbers, int AMOUNT, string oFileName, string sortedType); //will count number of moves in a bubble sort
int selectionSort(vector<int> numbers, int AMOUNT, string oFileName, string sortedType); //will count number of moves in a selection sort
int insertionSort(vector<int> numbers, int AMOUNT, string oFileName, string sortedType); //will count number of moves in a selection sort
int shellSort(vector<int> numbers, int AMOUNT, string oFileName, string sortedType); //will count number of moves in a selection sort
int saveData(int finalSize, string oFileName, int totalLoopCount, int totalAssignmentCount, int dataCompareTotal, string sortedType, double seconds, int otherMoves); //saves the sorted data
void saveHeading(string oFileName); //saves the heading of each sorting type
int howManyNumbers(int i); //gets each variation of the vector

#endif
