#include <iostream> // cin, cout
#include <cassert>  // assert
#include <math.h>

using namespace std;
bool collatz_read(istream& r, int& i, int& j);
int collatz_eval(int i, int j);
void collatz_print(ostream& w, int i, int j, int v);
void collatz_solve(istream& r, ostream& w);

int main()
{
	collatz_solve(cin, cout);
	return 0;
}

bool collatz_read (istream& r, int& i, int& j) 
{
    if (!(r >> i))
        return false;
    r >> j;
    return true;
}

int collatz_eval (int i, int j) 
{
    // <your code>
    assert( i > 0 && j > 0);                     // check preconditions
    int cur_max = 0;                                 // the max cycle length between i and j
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
        cur_max = max(cur_max,temp_max);        //checks to see if the make of K is larger than current max
    }
    return cur_max;                             //returns max
    //return 1;                     
}

void collatz_print (ostream& w, int i, int j, int v) 
{
    w << i << " " << j << " " << v << endl;
}

void collatz_solve (istream& r, ostream& w) 
{
    int i;
    int j;
    while (collatz_read(r, i, j)) 
    {
        const int v = collatz_eval(i, j);
		collatz_print(w, i, j, v);
	}
}