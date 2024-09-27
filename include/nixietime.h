/*
*   This file contains the truth table to convert K155ID1 inputs (A,B,C,D) to Nixie tube output.
*   TODO: Possibly some sort of aid in conversion directly to times polledd from the Windows timeserver?
*/


/*  VISUALISATION
*   D   C   B   A   OUT
*   L   L   L   L   0
*   L   L   L   H   1
*   L   L   H   L   2
*   L   L   H   H   3
*   L   H   L   L   4
*   L   H   L   H   5
*   L   H   H   L   6
*   L   H   H   H   7
*   H   L   L   L   8
*   H   L   L   H   9
*   REST NOT USED
*/

static int numArr[10][4] = {
    {0, 0, 0, 0},   // 0
    {0, 0, 0, 1},   // 1
    {0, 0, 1, 0},   // 2
    {0, 0, 1, 1},   // 3
    {0, 1, 0, 0},   // 4
    {0, 1, 0, 1},   // 5
    {0, 1, 1, 0},   // 6
    {0, 1, 1, 1},   // 7
    {1, 0, 0, 0},   // 8
    {1, 0, 0, 1}    // 9
};