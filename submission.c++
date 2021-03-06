// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

//cycle length
int cycle_length(long int num){
    //cout<<num <<" : ";
    int length = 1;
    while(num>1){
      if(num % 2 == 1) {
        num = num+(num>>1)+1; 
        length+=2;
      }
      else {
        num = num >> 1;
        ++length;
      }
    }
    //cout << length<<"\n";
    return(length);
}

void swap(int& a, int &b){
  a = a ^ b;
  b = b ^ a;
  a = a ^ b;
}

// ------------
// collatz_eval
// ------------
int collatz_eval (int i, int j) {
    int max_cycle_length = cycle_length(i) ;
    int current_cycle_length;
    if(i>j) swap(i,j);
    for(long int num = i+1; num<=j;num++){
      current_cycle_length=cycle_length(num);
      if(current_cycle_length>max_cycle_length) {
        max_cycle_length= current_cycle_length;
      }
    }
    return(max_cycle_length);
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}
        cout<<endl;}
// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// -------------------------------

// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}

/*
% g++ -pedantic -std=c++11 -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz



% cat RunCollatz.in
1 10
100 200
201 210
900 1000



% RunCollatz < RunCollatz.in > RunCollatz.out



% cat RunCollatz.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/
