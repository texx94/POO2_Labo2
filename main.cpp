#include "String.hpp"

#include <iostream>

using namespace std;

int main() {
   String c1("qwe");
   String c2("rtz");
   cout << c1 + c2 << endl << c1 << endl << c2 << endl;
   String c3;
   cin >> c3;
   cout << c3;
   return 0;
}