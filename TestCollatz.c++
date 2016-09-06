// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read_1) 
{
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);
}
TEST(CollatzFixture, read_2) 
{
    istringstream r("1000 200\n");
    int i;
    int j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(1000, i);
    ASSERT_EQ(200, j);
}
TEST(CollatzFixture, read_3)
{
    istringstream r("123 456\n");
    int i;
    int j;
    const bool b = collatz_read(r,i,j);
    ASSERT_TRUE(b);
    ASSERT_EQ(123,i);
    ASSERT_EQ(456,j);
}
TEST(CollatzFixture, read_4)
{
    istringstream r("111 222\n");
    int i;
    int j;
    const bool b = collatz_read(r,i,j);
    ASSERT_TRUE(b);
    ASSERT_EQ(111,i);
    ASSERT_EQ(222,j);
}
// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) 
{
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());
}
TEST(CollatzFixture, print_2) 
{
    ostringstream w;
    collatz_print(w, 100, 200, 125);
    ASSERT_EQ("100 200 125\n", w.str());
}
TEST(CollatzFixture, print_3) 
{
    ostringstream w;
    collatz_print(w, 201, 210, 89);
    ASSERT_EQ("201 210 89\n", w.str());
}
TEST(CollatzFixture, print_4) 
{
    ostringstream w;
    collatz_print(w, 900, 1000, 174);
    ASSERT_EQ("900 1000 174\n", w.str());
}



// -----
// solve
// -----

TEST(CollatzFixture, solve_1) 
{
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}
TEST(CollatzFixture, solve_2) 
{
    istringstream r("6 11\n71 94\n62 61\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("6 11 20\n71 94 116\n62 61 108\n", w.str());
}
TEST(CollatzFixture, solve_3) 
{
    istringstream r("840 408\n47 61\n40 435\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("840 408 171\n47 61 113\n40 435 144\n", w.str());
}
TEST(CollatzFixture, solve_4) 
{
    istringstream r("83 3350\n5 29741\n6 63557\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("83 3350 217\n5 29741 308\n6 63557 340\n", w.str());
}


