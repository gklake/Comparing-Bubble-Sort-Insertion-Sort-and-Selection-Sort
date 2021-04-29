/* -----------------------------------------------------------------
  Starting code for a sort comparison assignment. Original 
  source: Gaddis Book: 
  Chapter 7: Programming Challenge #7
  Updated by Dr. Byun & Dr. Gross for CST238.

-------------------------------------------------------------------*/
/*
* Title: hw08-2
* Abstract: This program will compare the elapsed time, swaps, and comparisons of 3 sorting algorithims - Bubble, Insertion, and Selection sort.
* Author: Gabrielle Lake
* Email: glake@csumb.edu
* Estimate: 3 hours
* Date: 11/07/2020
* 
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include "mysorts.h"
using namespace std;

// Function prototypes
int * readNumbers(string filename, int & size);

int main() {

    cout << "Enter filename: ";
    string filename;
    cin >> filename;
    int size = 0;
    // Read the numbers into the array.
    int * a = readNumbers(filename, size);
    int * b = copyArray(a, size);
    int * c = copyArray(a, size);
    int * d = copyArray(a, size);
    
    bubble_sort(a, size);
    insertion_sort(b, size);
    fast_insertion_sort(d, size);
    selection_sort(c, size);
    return 0;
}

// ********************************************************
// The readNumbers function reads numbers from inFile and *
// stores them in the numbers array.                      *
// ********************************************************
int * readNumbers(string filename, int & size) {
        // File stream object
    ifstream inFile;

    // Open the input file.
    inFile.open(filename);

    // Test for errors.
    if (!inFile) {
        cout << "Error opening the file.\n";
        return 0;
    }

    inFile >> size;
    // Array to hold the numbers
    int * a = new int[size];
    for (int i = 0; i < size; i++) {
        inFile >> a[i];
    }
    return a;
}


