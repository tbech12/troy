//Troy Bechtold
//2/5/2020
//CS 122
//Project 2

//Library 
#include "librarySorting.h" //so that file can use librarys

//input and output of emails
string fileName(string fileType, string sortType)
{
  //data
  string fileName; //file name
  string fileNameExt;// ext on file
  
  //inputfile
  do
  {
    cout << "Please enter " << fileType << "file name for " << sortType << ":"; 
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
        saveHeading(fileName);
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

//gets amount of number
int howManyNumbers(int i)
{
  //data
  //i the current for loop counter
  int amountOfNumbers;
  
  //program
    if (i == 0)
    {
      amountOfNumbers = 500; //new amount
    } //if i = 0
    else if (i == 1)
    {
      amountOfNumbers = 1000; //new amount
    } //if i = 1
    else if (i == 2)
    {
      amountOfNumbers = 5000; //new amount
    } //if i = 2
    else if (i == 3)
    {
      amountOfNumbers = 10000; //new amount
    } //if i = 3
    return(amountOfNumbers);
}//how many numbers 

//sorted number creation
int sortedVector(vector<int> numbers, int total, string oFileNameBubble, string oFileNameSelection, string oFileNameInsertion, string oFileNameShell)
{
  //data
  int i; //loop counter
  
  //program
  for (i = 1; i <= total; i++)
  {
    numbers.push_back(i); //saves to vector
  }//for loop
  bubbleSort(numbers, total, oFileNameBubble, "Sorted N:"); //sent out to the get bubble sorted
  insertionSort(numbers, total, oFileNameInsertion, "Sorted N:"); //sent out to get insertion sorted 
  selectionSort(numbers, total, oFileNameSelection, "Sorted N:"); //sent out to get selection sorted
  shellSort(numbers, total, oFileNameShell, "Random Sorted N:"); //sent out to get shell sorted
  return 0;
}//get a vector full of numbers

int reversedSortedVector(vector<int> numbers, int total, string oFileNameBubble, string oFileNameSelection, string oFileNameInsertion, string oFileNameShell)
{
  //data
  int i; //loop counter
  int j = total + 1; //total + 1 to get reverse
  
  //program
  while (j != 0)
  {
    numbers.push_back(j + 1); //saves to vector
    j = j - 1; //takes one off the total
  }//while loop
  bubbleSort(numbers, total, oFileNameBubble, "Descending Sorted N:"); //sent out to the get bubble sorted
  insertionSort(numbers, total, oFileNameInsertion, "Descending Sorted N:"); //sent out to get insertion sorted 
  selectionSort(numbers, total, oFileNameSelection, "Descending Sorted N:"); //sent out to get selection sorted
  shellSort(numbers, total, oFileNameShell, "Random Sorted N:"); //sent out to get shell sorted
  return 0;
}//get a vector full of numbers

int randVectorNumbers(vector<int> numbers, int total, string oFileNameBubble, string oFileNameSelection, string oFileNameInsertion, string oFileNameShell)
{
  //data
  int randomNumber; //random number
  int i; //loop counter
  int j = total; //sets j to total
  srand(time(0)); //for random number
  
  //program
  for (i = 1; i <= total; i++)
  {
    randomNumber = (1 + (rand() % total)); //gets a random number
    numbers.push_back(randomNumber); //saves number to the vector
  }//for loop
  bubbleSort(numbers, total, oFileNameBubble, "Random Sorted N:"); //sent out to the get bubble sorted
  insertionSort(numbers, total, oFileNameInsertion, "Random Sorted N:"); //sent out to get insertion sorted 
  selectionSort(numbers, total, oFileNameSelection, "Random Sorted N:"); //sent out to get selection sorted
  shellSort(numbers, total, oFileNameShell, "Random Sorted N:"); //sent out to get shell sorted
  return 0;
}//random numbers

//to sort the file in bubble format
int bubbleSort(vector<int> numbers, int AMOUNT, string oFileName, string sortedType)
{
  //data
  //line = line from file
  int i = 0; //loop counter
  int j = 0; //loop counter
  int temp; //temp string
  int loopcounter = 0; //counter for moves
  int assignmentcount = 3; //assignment counter
  int dataCompare = 0; //data comparison counter
  int otherMoves = 0; //other moves counter
  double seconds; //seconds to sort
  auto start = high_resolution_clock::now(); //to take time of the process

  //program
  // sort the names by alpha
  for (i = 0; i < AMOUNT; i++)
  {
    loopcounter++; //add 1 to loop
    otherMoves++; //add 1 to other
    for (j = i + 1; j < AMOUNT; j++)
    {
      loopcounter++; //add 1 to loop
      otherMoves++; //add 1 to other
      dataCompare ++; //add one to data counter
      if (numbers[i] > numbers[j])
      {
        temp = numbers[i]; //sets temp equal to the smaller
        numbers[i] = numbers[j]; //bumps up one spot
        numbers[j] = temp; //sets the lower number to the open space
        assignmentcount += 2; //add 2 to assignment
        otherMoves ++; //add 1 to other
      }//if statement
    }//for loop
  }//for loop
  auto stop = high_resolution_clock::now(); //stops clock
  auto duration = duration_cast<microseconds>(stop - start);  //sets duration
  seconds = duration.count();
  saveData(AMOUNT, oFileName, loopcounter, assignmentcount, dataCompare, sortedType, seconds, otherMoves);
  return 0;
}//bubble sort

//selector sort function
int selectionSort(vector<int> numbers, int AMOUNT, string oFileName, string sortedType)
{
  //data
  int startScan; //start 
  int minIndex; //location of min
  int minValue;  //min value
  int index;  //location
  int loopcounter = 0; //counter for moves
  int assignmentcount = 4;  // # assignments 
  int dataCompare = 0; //data compared
  int otherMoves = 0; //num of moves
  double seconds; //seconds to complete 
  auto start = high_resolution_clock::now(); //starts the clock 
  
  //program
  for (startScan = 0; startScan < (AMOUNT - 1); startScan++)
  {
    loopcounter++;//adds to loop counter
    assignmentcount += 2;//adds 2 to assignment
    minIndex = startScan; //new min value
    minValue = numbers[startScan];// mew min value
    dataCompare++; //add one to data compare
    otherMoves++; //add one to other
    for(index = startScan + 1; index < AMOUNT; index++)
    {
      loopcounter++; //add to loop counter
      assignmentcount++; //add to assignment count
      if (numbers[index] < minValue)
      {
        minValue = numbers[index]; //new min value
        minIndex = index; //new min index
        assignmentcount += 2; //add 2 to assingment counter
      }//is statement
    }//for loop
    assignmentcount += 2; //assignment counter
    numbers[minIndex] = numbers[startScan]; //swaps numbers
    numbers[startScan] = minValue; //new min value to start at
  } //for loops
  auto stop = high_resolution_clock::now(); //stop timer
  auto duration = duration_cast<microseconds>(stop - start);//sets duration
  seconds = duration.count();
  saveData(AMOUNT, oFileName, loopcounter, assignmentcount, dataCompare, sortedType, seconds, otherMoves);
  return 0;
}//selection sort

//insertionsort function
int insertionSort(vector<int> numbers, int AMOUNT, string oFileName, string sortedType)
{
  //data
  int i; //loop counter
  int j; //loop counter 
  int currValue;  //current val
  int assignmentcount = 3; //assignment counter
  int loopcounter = 0; //loop counter
  int dataCompare = 0; //data compare
  int otherMoves = 0; //other moves
  double seconds; //seconds ot complete 
  auto start = high_resolution_clock::now(); //starts clock
  
  //program
  for (i = 1; i < AMOUNT; i++)
  { 
    j = i - 1; // one less than i
    loopcounter++; //add to loop 
    dataCompare++; //add to data 
    while (j >= 0 && currValue < numbers[j])
    {
      numbers[j + 1] = numbers[j]; //replaces number
      j--; //decrease j
      loopcounter++; //add to loop
      assignmentcount++; //add to assignment
    }//while loop
    numbers[j + 1] = currValue; //new value for hole
    assignmentcount++; //add to assignment
  }//for loop
  auto stop = high_resolution_clock::now(); //stops clock
  auto duration = duration_cast<microseconds>(stop - start); //sets duration
  seconds = duration.count();
  saveData(AMOUNT, oFileName, loopcounter, assignmentcount, dataCompare, sortedType, seconds, otherMoves);
  return 0;
}//insertion sort

/* function to sort arr using shellSort */
int shellSort(vector<int> numbers, int AMOUNT, string oFileName, string sortedType) 
{ 
  //data
  int gap;
  int i;
  int temp;
  int j;
  int assignmentcount = 4; //assignment counter
  int loopcounter = 0; //loop counter
  int dataCompare = 0; //data compare
  int otherMoves = 0; //other moves
  double seconds; //seconds ot complete 
  auto start = high_resolution_clock::now(); //starts clock
  
  //program
  for (gap = AMOUNT/2; gap > 0; gap /= 2) 
  { 
    loopcounter++; //add one to loop counter
    otherMoves++; //add one to other moves
    for (i = gap; i < AMOUNT; i += 1) 
    { 
      temp = numbers[i]; //temp assigned numbers [i]
      dataCompare++; //add one to data compare
      assignmentcount++; //add one to assignment counter
      loopcounter++; //add one to loop counter
      otherMoves++;  //add one to other move
      for (j = i; j >= gap && numbers[j - gap] > temp; j -= gap) 
      {
        numbers[j] = numbers[j - gap]; //moves the int
        numbers[j] = temp; //moves position of int
        assignmentcount++; //add one to assignment counter
        loopcounter++; //add one to loop counters
        otherMoves ++; //add one to other moves
      } //for loop
    } //for loop
  } //for loop
  auto stop = high_resolution_clock::now(); //stops clock
  auto duration = duration_cast<microseconds>(stop - start); //sets duration
  seconds = duration.count();
  saveData(AMOUNT, oFileName, loopcounter, assignmentcount, dataCompare, sortedType, seconds, otherMoves);
  return 0; 
} 

//save data to file
int saveData(int finalSize, string oFileName, int totalLoopCount, int totalAssignmentCount, int dataCompareTotal, string sortedType, double seconds, int otherMoves)
{
  //data 
  //oFile = outpt file
  //converted = string to save
  //next line = if there is a new line
  ofstream fout; //output 
  int totalNum = totalLoopCount + totalAssignmentCount + dataCompareTotal + otherMoves;// gets the total number of moves
  
  //program
  fout.open (oFileName.c_str(), ios:: app); //opens output file
  if(!(fout.good()))throw "I/O error"; //if not good
  fout << sortedType << finalSize << ", " << seconds << ", "<< totalLoopCount << ", " << totalAssignmentCount << ", " << dataCompareTotal << ", " << otherMoves << ", " << totalNum << endl; //outputs to file
  fout.close(); //close file
  return 0;
}//saves

//saves the heading of the file
void saveHeading(string oFileName)
{
  //data
  ofstream fout; //output 
  
  //program
  fout.open (oFileName.c_str(), ios:: app); //opens output file
  if(!(fout.good()))throw "I/O error"; //if not good
  fout << "Vector Configuration, Mirco-seconds, #Loop Comparison, #Data Assignments, #Data Comparison, #Others, Total" << endl; //sets the heading of the file
  fout.close(); //close file
}//save heading
