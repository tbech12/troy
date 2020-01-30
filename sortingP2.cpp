//Troy Bechtold
//1/22/2020
//CS 122
//Project 1

//Librarys
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

//User Defined Functions
string fileName(string fileType);
int randVectorNumbers(vector<int> numbers, int total, string oFileName);
int sortedVector(vector<int> numbers, int total, string oFileName);
int reversedSortedVector(vector<int> numbers, int total, string oFileName);
int bubbleSort(vector<int> numbers, int AMOUNT, string oFileName); //will count number of moves in a bubble sort
int selectionSort(vector<int> numbers, int AMOUNT, string oFileName); //will count number of moves in a selection sort
int insertionSort(vector<int> numbers, int AMOUNT, string oFileName); //will count number of moves in a selection sort
int saveData(int finalSize, string oFileName, int totalLoopCount, int totalAssignmentCount, int dataCompareTotal); //saves the sorted data
void saveHeading(string oFileName);

//Main Program
int main()
{
  //Data
  string oFileName; //output file name
  vector <int> vectorOfNumbers; //vector to store numbers

  //program FileName
  oFileName = fileName("output "); //gets output file
  saveHeading(oFileName);
  sortedVector(vectorOfNumbers, 500, oFileName);
  reversedSortedVector(vectorOfNumbers, 500, oFileName);
  randVectorNumbers(vectorOfNumbers, 500, oFileName);
  
}//main

//input and output of emails
string fileName(string fileType)
{
  //data
  string fileName; //file name
  string fileNameExt;// ext on file
  
  //inputfile
  do
  {
    cout << "Please enter " << fileType << "file name: "; 
    getline (cin, fileName); //gets file name
    if (fileName.length() == 0) //if equal to 0 
    {
      return fileName;
      break;
    }//if 0
    else if (fileName.length() < 5)
    {
      cout << endl << "Invalid file name" << endl << endl;
    }//if less than 5
    else if (fileName.length() >= 5)
    {	
      fileNameExt = fileName.substr(fileName.length()-4, 4); //looks at the last 4 to .txt
      if (fileNameExt == ".txt" || fileNameExt == ".csv")
      {
        return fileName;
        break;
      } // if it has .txt
      else if (fileNameExt != ".txt" || fileNameExt != ".csv") //if .txt
      {
        cout << endl << "Invalid file name does not end with .txt" << endl << endl;
      } //if not .txt
    }// if greater than 5
  }while (fileName.length() < 5 || fileNameExt != ".txt"); //while its greater than 5 and includes .txt
  return 0;
}//email program

int sortedVector(vector<int> numbers, int total, string oFileName)
{
  //data
  int i;
  
  //program
  for (i = 1; i <= total; i++)
  {
    numbers.push_back(i);
  }//for loop
  //for (i = 1; i < total; i++)
  //{
    //cout << numbers.at(i) << endl;
  //}
  bubbleSort(numbers, total, oFileName);
  insertionSort(numbers, total, oFileName);
  return 0;
}//get a vector full of numbers

int reversedSortedVector(vector<int> numbers, int total, string oFileName)
{
  //data
  int i;
  int j = total;
  
  //program
  while (total + 1 != 0)
  {
    numbers.push_back(total + 1);
    total = total - 1;
  }//while loop
  //for (i = 1; i < j + 1; i++)
  //{
    //cout << numbers.at(i) << endl; 
  //}//for loop
  bubbleSort(numbers, total, oFileName);
  insertionSort(numbers, total, oFileName);
  return 0;
}//get a vector full of numbers

int randVectorNumbers(vector<int> numbers, int total, string oFileName)
{
  //data
  int randomNumber; //random number
  int i;
  int j = total;
  srand(time(0));
  
  //program
  for (i = 1; i <= total; i++)
  {
    randomNumber = (1 + (rand() % total));
    numbers.push_back(randomNumber);
  }//for loop
  //for (i = 1; i < j; i++)
  //{
    //cout << numbers.at(i) << endl; 
  //}//for loop
  bubbleSort(numbers, total, oFileName);
  insertionSort(numbers, total, oFileName);
  return 0;
}//random numbers

//to sort the file in bubble format
int bubbleSort(vector<int> numbers, int AMOUNT, string oFileName)
{
  //data
  //line = line from file
  int i = 0; //loop counter
  int j = 0; //loop counter
  int temp; //temp string
  int loopcounter = 0; //counter for moves
  int assignmentcount = 3; 
  int dataCompare = 0;

  //program
  // sort the names by alpha
  for (i = 0; i < AMOUNT; i++)
  {
    loopcounter++;
    for (j = i + 1; j < AMOUNT; j++)
    {
      loopcounter++;
      if (numbers[i] > numbers[j])
      {
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
        loopcounter++;
        dataCompare++;
        assignmentcount += 3;
      }//if statement
    }//for loop
  }//for loop
  saveData(AMOUNT, oFileName, loopcounter, assignmentcount, dataCompare);
  return 0;
}//bubble sort

//selector sort function
int selectionSort(vector<int> numbers, int AMOUNT, string oFileName)
{
  //data
  int loopcounter = 0; //counter for moves
  int assignmentcount = 0; 
  int dataCompare = 0;
  //program
  
  return 0;
}//selection sort

//insertionsort function
int insertionSort(vector<int> numbers, int AMOUNT, string oFileName)
{
  //data
  int i;  //loop counter
  int j;  //loop counter 
  int currValue;  //current val
  int assignmentcount = 3;
  int loopcounter = 0;
  int dataCompare = 0;
    
  //program
  for (i = 1; i < AMOUNT; i++) //i = 1, loopControlAssignment ++
  { 
    j = i - 1;
    loopcounter++;
    while (j >= 0 && currValue < numbers[j])
    {
      numbers[j + 1] = numbers[j];
      j--;
      loopcounter++;
      assignmentcount++;
      dataCompare++;
    }//while loop
    numbers[j + 1] = currValue;
    assignmentcount++;
  }//for loop
  //i < size, loopcontrolCompare++
  //for the last time the bc evalues to false
  saveData(AMOUNT, oFileName, loopcounter, assignmentcount, dataCompare);
  return 0;
}//insertion sort

int saveData(int finalSize, string oFileName, int totalLoopCount, int totalAssignmentCount, int dataCompareTotal)
{
  //data 
  //oFile = outpt file
  //converted = string to save
  //next line = if there is a new line
  ofstream fout; //output 
  string sortedType = "Its some type";
  int otherMoves = 0;
  int seconds = 0;
  int totalNum = totalLoopCount + totalAssignmentCount + dataCompareTotal + otherMoves;
  
  //program
  fout.open (oFileName.c_str(), ios:: app); //opens output file
  if(!(fout.good()))throw "I/O error"; //if not good
  fout << sortedType << "," << seconds << ", "<< totalLoopCount << ", " << totalAssignmentCount << ", " << dataCompareTotal << ", " << otherMoves << ", " << totalNum << endl;
  fout.close(); //close file
  return 0;
}//saves

void saveHeading(string oFileName)
{
  //data
  ofstream fout; //output 
  
  //program
  fout.open (oFileName.c_str(), ios:: app); //opens output file
  if(!(fout.good()))throw "I/O error"; //if not good
  fout << "Vector Configuration, Seconds, #Loop Comparison, #Data Assignments, #Data Comparison, #Others, Total" << endl;
  fout.close(); //cloes file
}//save heading
