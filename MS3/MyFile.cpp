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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "MyFile.h"
using namespace std;
namespace sict{

  MyFile::MyFile(const char* fname){
    text_[0] = char(0);
    strcpy(fname_, fname);
  }
  fstream& MyFile::store(std::fstream& file, bool addNewLine)const{
    file.open(fname_, ios::app|ios::out);
    int i = 0;
    while (text_[i]){
      file << text_[i];
      i++;
    }
    file.close();
    return file;
  }
  fstream& MyFile::load(std::fstream& file){
    file.open(fname_, ios::in);
    int i=0;
    while (!file.fail()){
      text_[i++] = file.get();
    }
    file.clear();
    file.close();
    if(i > 0) i--;
    text_[i] = 0;
    return file;
  }
  ostream& MyFile::write(std::ostream& os, bool linear)const{
    for (int i = 0; text_[i]; i++){
      if (linear && text_[i] == '\n'){
        os << " ";
      }
      else{
        os << text_[i];
      }
    }
    return os;
  }
  istream& MyFile::read(std::istream& is){
    is.getline(text_, 9999, EOF);
    return is;
  }
  void MyFile::print(){
    write(cout, false);
    cout << endl;
  }
  std::ostream& operator<<(std::ostream& ostr, const MyFile& mf){
    return mf.write(ostr, true);
  }
  std::istream& operator>>(std::istream& istr, MyFile& mf){
    return mf.read(istr);
  }
}