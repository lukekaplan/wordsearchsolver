//Luke Kaplan
//sjd7wr
//10-17-22
//hashTable.cpp

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <cmath>
#include "hashTable.h"
#include "timer.h"

using namespace std;

hashTable::hashTable(int size){
  theSize = size;
  //fill the vector with empty lists (collection)
  for(int i = 0; i < theSize; i++){
    list<string> collection;
    v1.push_back(collection);
  }
  
}

hashTable::~hashTable(){
  
}
  

int hashTable::hashFunction(string s){
  int powers[23] = {1,37,1369, 50653, 1874161, 69343957,  (37*37 * 37*37 * 37*37), (37*37 * 37*37 * 37*37 * 37), (37*37 * 37*37 * 37*37 * 37*37),
		  (37*37 * 37*37 * 37*37 * 37*37 * 37), (37*37 * 37*37 * 37*37 * 37*37 * 37*37), (37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37),
		  (37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37), (37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37), (37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37),
		  (37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37), (37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37),
		  (37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37), (37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37),
		  (37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37),  (37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37 * 37*37),
		  (37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37),  (37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37*37) };

  //cout << s << endl;
  int sum = 0;
  /*if(s.length() == 1){
    sum += s.at(0);
  }
  else if (s.length() == 2){
    sum += s.at(0) + s.at(1);
  }
  else {
    sum += s.at(0) + s.at(1) + s.at(2);
  }
  for(int i = 0; i < s.length(); i++){
    sum += s.at(i);
    }*/

  sum = s.at(0) * powers[s.length()];
  //sum = s.at(0) * 37 * s.length();
  if(sum < 0){
    sum = sum * -1;
  }
  return sum;
}

void hashTable::insert(string s){
  //separate chaining
  int hashResult = hashFunction(s) % v1.size();
    v1[hashResult].push_front(s);

  //linear probing
  /*int hashResult = hashFunction(s) % v1.size();
  if (v1[hashResult].size() == 0){
    v1[hashResult].push_front(s);
  } else {
    while(v1[hashResult].size() > 0){
      hashResult++;
      if(hashResult >= v1.size()-1){
	hashResult = 0;
      }
    }
    v1[hashResult].push_front(s);

    }*/

}

bool hashTable::find(string s){
  //separate chaining
  int hashLocation = hashFunction(s) % v1.size();
  list<string>::iterator it1;
  it1 = v1[hashLocation].begin();
  if(*it1 == s){
    return true;
  } else {
    for(it1; it1!= v1[hashLocation].end(); it1++){
      if(*it1 == s){
	return true;
      }
    }
    return false;

  }

  //linear probing
  /*int hashLocation = hashFunction(s) % v1.size();
  if(v1[hashLocation].front() == s){
    return true;
  } else {
    while(v1[hashLocation].front() != s){
      if(hashLocation >= v1.size() - 1){
	hashLocation = 0;
      }
      if(v1[hashLocation].size() == 0){
	return false;
      }
      else {
	hashLocation++;
      }
    }
    return true;
    }*/
  
}



		     
