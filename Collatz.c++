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
#include <math.h>   // max, min

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) {
    if (!(r >> i))
        return false;
    r >> j;
    return true;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) 
{
    // <your code>
    assert( i > 0 && j > 0);                     // check preconditions
    int max = 0;                                 // the max cycle length between i and j
    int temp_max = 1;                            // the cycle length for a number between i and j
    for(int k = min(i,j); k<= max(i,j); k++)     // iteraties through the numbers between i and j
    {
        int temp_num = k;                        // the number we want to find the cycle the length first   
        temp_max = 1;                            // sets the default cycle length to 1
        while(temp_num !=1)                      // begins the basic collatz conjecture
        {
            if(temp_num % 2 == 0)
            {
                temp_num /= 2;
                ++temp_max;
            }
            else
            {
                temp_num = 3 * temp_num +1;
                ++temp_max;
            }
        }
        max = max(max,temp_max);
    }
    return max;                     
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
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
