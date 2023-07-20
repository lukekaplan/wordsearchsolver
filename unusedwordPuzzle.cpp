//Luke Kaplan
//sjd7wr
//10-17-22
//wordPuzzle.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>

using namespace std;
int main (int argc, char **argv){
  unordered_set <string> dictionary;
  
  //try to open the file
  ifstream file(argv[1]);
  string word;
  
  if(!file.is_open()){
    cout << "file is not opened" << endl;
  }
  else {
    while(getline(file, word)){
      //needs to call my hash table here
      dictionary.insert(word);
    }
  }

  file.close();

  
   // attempt to read in the file
  ifstream file2(argv[2]);
  int rows;
  int cols;
  
   readInGrid(argv[2], rows, cols);



  //ifstream file2(argv[2]);
  // int rows = 11;
  //int cols = 20;
  //char myGrid[500][500];
  //readInGrid(argv[2], rows, cols);
  return 0;
}
