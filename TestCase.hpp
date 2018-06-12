#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class TestCase{
    public:
        string nameOfCheck;
        ostream& os;
        int failed, passed, total;

        TestCase (string msg , ostream& os);

          template <typename T> TestCase& check_equal(T x, T y){
            total ++;
            if (x==y){
                passed ++;
            }
            else{
                failed ++;
                os << nameOfCheck << " Failure in test #" << total << ":" << x << " should equal " << y << "!" << endl;
            }
            return (*this);
        }

          template <typename T> TestCase& check_different( T x, T y){
            total++;
            if (x!=y){
                passed ++;
            }
            else{
                os << nameOfCheck << " Failure in test #" << total << ":" << x << " should different " << y << "!" <<endl;
                failed ++;
            }
            return (*this);
        }

          template <typename T, typename F > TestCase& check_function ( F fun, T x, int y){
           total++;
            if ((*fun)(x) == y){
                passed ++;
            }
            else{
                failed ++;
                os << nameOfCheck << " Failure in test #" << total << ": Function should return " << y << " but returned " << fun(x) << "!" <<endl;

            }
            return (*this);
        }

        template <typename T> TestCase& check_output(T a, string temp){
          ostringstream ss;
          ss<<a;
          total++;
          if(ss.str()==temp)
            passed++;
          else{
            failed++;
            os << nameOfCheck << " Failure in test #" << total << ": Function should return " << temp << " but returned " <<ss.str() << "!" <<endl;
          }
          return (*this);
        }

      friend ostream& operator << (ostream& os, TestCase& a);
        void print();
};
