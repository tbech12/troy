//Troy Bechtold
//2/5/2020
//CS 122
//Project 2

//Library 
#include "librarySorting.h" //so that file can use librarys

//Main Program
int main()
{
  //Data
  string oFileNameBubble; //output file name
  string oFileNameSelection; //output file name
  string oFileNameInsertion; //output file name
  string oFileNameShell; //out file 
  vector <int> vectorOfNumbers; //vector to store numbers
  int i; //loop counter
  int numNumbers = 500; //start number of numbers for the vector

  //program FileName
  oFileNameBubble = fileName("output ", "Bubble sort"); //gets output file
  oFileNameSelection = fileName("output ", "Selection sort"); //gets output file
  oFileNameInsertion = fileName("output ", "Insertion sort"); //gets output file
  oFileNameShell = fileName("output ", "Shell sort"); //gets output file
  for (i = 0; i < 4; i++)
  {
    numNumbers = howManyNumbers(i); //calls functions to get the next set of numbers
    sortedVector(vectorOfNumbers, numNumbers, oFileNameBubble, oFileNameSelection, oFileNameInsertion, oFileNameShell); //sends out x amount of numbers to create in sorted form
  } //for loop
  for (i = 0; i < 4; i++)
  {
    numNumbers = howManyNumbers(i); //calls functions to get the next set of numbers
    reversedSortedVector(vectorOfNumbers, numNumbers, oFileNameBubble, oFileNameSelection, oFileNameInsertion, oFileNameShell); //sends out x amount of numbers to create for reversed sorted form
  } //for loop
  for (i = 0; i < 4; i++)
  { 
    numNumbers = howManyNumbers(i); //calls functions to get the next set of numbers
    randVectorNumbers(vectorOfNumbers, numNumbers, oFileNameBubble, oFileNameSelection, oFileNameInsertion, oFileNameShell ); //sends out x amount of numbers to create for rand vector numbers
  } //for loop
}//main
