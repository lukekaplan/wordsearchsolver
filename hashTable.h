//Luke Kaplan
//sjd7wr
//10-17-22
//hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <list>
using namespace std;

class hashTable {
 public:
  hashTable(int size);
  ~hashTable();
  void insert(string key);
  bool find(string s);
  int hashFunction(string s);
  
 private:
  vector< list <string> > v1;
  int theSize;


};
#endif
