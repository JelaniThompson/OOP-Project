// Final Project Milestone 3
// Version 1.0
// Date	2017-07-10
// Author	Fardad Soleimanloo
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "MyFile.h"
using namespace std;
using namespace sict;
int main(){  
  fstream file("ms3.txt", ios::out);
  file << "one" << endl << "two" << endl;
  file.close();
  MyFile F("ms3.txt");
  F.load(file);
  cout << "Linear: " << F << endl;
  cout << "As is: " << endl;
  F.print();
  cout << "Enter the following: " << endl << "three<ENTER>" << endl << "four<ENTER>" << endl << "Ctrl-Z<ENTER>" << endl << endl;
  cin >> F;
  F.store(file, true);
  F.load(file);
  cout << F << endl;
  F.print();
  return 0;
}