#include "TestCase.hpp"

TestCase::TestCase (string msg , ostream& os): os(os),failed(0),passed(0),total(0){
    nameOfCheck =msg;
}
ostream& operator <<(ostream& os,  TestCase& a){
  return a.os;
}

void TestCase:: print(){
  os << nameOfCheck <<":" << failed << " failed, " <<passed << "  passed, " << total << " total" <<endl;
  cout<<(*this);
}
