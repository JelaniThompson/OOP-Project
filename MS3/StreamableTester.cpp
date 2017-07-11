// Final Project Milestone 3
// Version 1.0
// Date	2017-07-06
// Author	Fardad Soleimanloo
//
// this is not the main that is used as a tester for submitting
// milestone 3. See ms3_tester.cpp for the submission tester.
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
  fstream file;
  MyFile F("streamable.txt");
  cout << "Run this program few times and keep adding to" <<endl<<"the content of the file created." << endl;
  F.load(file);
  cout << "Linear content of file streamable.txt: " << endl << endl << F << endl;
  cout << "Press <ENTER> to continue...";
  cin.ignore();
  cout << endl << "streamble.txt as is: " << endl;
  F.print();
  cout << " ---------------- " << endl << "Enter a text and then"
        <<endl<<"On windows end it with in a new line with Ctrl-Z <ENTER>"
        <<endl<<"On Linux or mac end it with a new line with Ctrl-D" 
        <<endl<< "to append to the end of streamable.txt:" << endl;
  cin >> F;
  F.store(file, true);
  cout << "Re-run the program to see the appended lines." << endl;
  return 0;
}