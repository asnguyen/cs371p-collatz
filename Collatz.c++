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
#include <math.h>   // max, min. exp2

#include "Collatz.h"

using namespace std;

#define ARRAY_SIZE 300000

// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) 
{
    if (!(r >> i))
        return false;
    r >> j;
    return true;
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) 
{
    // <your code>
    #ifndef ARRAY_SIZE
        assert( i > 0 && j > 0);                     // check preconditions
        int cur_max  = 0;                            // the max cycle length between i and j
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
            assert(temp_max > 0);
            cur_max = max(cur_max,temp_max);        //checks to see if the make of K is larger than current max
        }
        assert(cur_max > 0);
        return cur_max;                             //returns max
    #endif

    #ifdef ARRAY_SIZE
        assert(i > 0 && j >0);
        int cur_max  = 0;
        int temp_max = 1;
        int my_cache[ARRAY_SIZE];                   //this will be our cache
        for(int a = 0; a < ARRAY_SIZE; ++a)         
        {
            my_cache[a] = 0;                        //assigns 0 to all elements of the cache
        }
        for(int a = 0; a <=18; ++a)
        {
            my_cache[((int)exp2(a))] = a + 1;       //eagerly puts in some cycle lengths to our cache
        }
        for(int k = min(i,j); k<= max(i,j); k++)
        {
            int temp_num = k;
            temp_max = 1;
            while(temp_num !=1)
            {
                if(temp_num % 2 ==0)
                {
                    temp_num /= 2;
                }
                else
                {
                    temp_num = 3 * temp_num +1;
                }
                if(temp_num <= ARRAY_SIZE)              //if k is a candidate for a cache entry
                {
                    if(my_cache[temp_num] != 0)         //is there a non-zero value for entry k
                    {
                        temp_max += my_cache[temp_num]; //add the value in the cache to the current value of the cycle length
                        temp_num = 1;                   //change the temp_num to 1 so that we can break out of the while loop
                    }
                    else
                    {
                        ++temp_max;                     //there is no entry for it yet so we just continue as normal
                    }
                }
                else
                {
                    if(temp_num > ARRAY_SIZE)
                        ++temp_max;                      //there is no entry for this temp_num (too big of a number)
                }
            }
            if(k<=ARRAY_SIZE)                            //if the entry does not exist yet add it
            {
                my_cache[k] = temp_max;
            }
            cur_max = max(cur_max,temp_max);
        }
        return cur_max;
    #endif

    //return 1;                     
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) 
{
    w << i << " " << j << " " << v << endl;
}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) 
{
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}















