/*
NOTE: I AM IMPLEMENTING THE FAST_INSERTION_SORT, MY COMPS VARIABLE IS CORRECT, BUT MY SWAPS VARIABLE IS NOT
*Gabrielle Lake 
*/

#include <time.h>
#include <iostream>
#include "mysorts.h"
using namespace std;

bool isSorted(int * values, int size) {
    for(int i = 0; i < size - 1; i++){
      if(values[i] > values[i+1]){
        return false;
      }
    }
    return true;
}

int * copyArray(int * source, int size) {
   int * tempArray = new int [size];
   for(int i = 0; i < size; i++){
     tempArray[i] = source[i];
   }
    return tempArray;
}
void bubble_sort (int * values, int size) {
    int comps = 0;
    int swaps = 0;
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the bubble sorting..." << endl;
    // Measure the starting clock and conduct the bubble sorting
    startClock = clock();
    // sorting code goes here
    int temp = 0;
    for(int i = 0; i < size - 1; i++)
    {
      for(int k = 0; k < size - i - 1; k++)
      {
        if(values[k] > values[k+1])
        {
          temp = values[k];
          values[k] = values[k+1];
          values[k+1] = temp;
          swaps++;  
        }
        comps++;
      }
    }


    elapsedTime = clock() - startClock;
    cout << "Bubble sort completed. Is sorted: " << boolalpha <<
        isSorted(values, size) << endl;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
        << " seconds" << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Comps: " << comps << endl << endl;
}

void insertion_sort (int * values, int size) {
    int comps = 0;
    int swaps = 0;
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the insertion sorting..." << endl;
    // Measure the starting clock and conduct the insertion sorting
    startClock = clock();
    // sorting code goes here
    for(int i = 1; i < size; i++){
      for(int k = i; k > 0; k--){
          if(values[k] < values[k-1]){
            
            int temp = values[k];
            values[k] = values[k - 1];
            values[k - 1] = temp;
            swaps++;
          } else {
            comps++;
            break;
          }
          comps++;
      }
    }
    elapsedTime = clock() - startClock;
    cout << "Insertion sort completed. Is sorted: " << boolalpha <<
        isSorted(values, size) << endl;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
        << " seconds" << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Comps: " << comps << endl << endl;
}

void selection_sort (int * values, int size) {
    int comps = 0;
    int swaps = 0;
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the selection sorting..." << endl;
    // Measure the starting clock and conduct the selection sorting
    startClock = clock();
    // sorting code goes here
    for(int i = 0; i < size-1; i++) {
      int minIndex = i;
      for(int j = i+1; j < size; j++){
        if(values[j] < values[minIndex]){  
          minIndex = j;     
        }
        comps++; 
      }
      if(minIndex != i){
        int temp;
        temp = values[minIndex];
        values[minIndex] = values[i];
        values[i] = temp;  
        swaps++;
      }
    }

    elapsedTime = clock() - startClock;
    cout << "Selection sort completed. Is sorted: " << boolalpha <<
        isSorted(values, size) << endl;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
        << " seconds" << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Comps: " << comps << endl << endl;
}

//EXTRA CREDIT
void fast_insertion_sort (int * values, int size){
    int comps = 0;
    int swaps = 0;
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the fast insertion sorting..." << endl;
    // Measure the starting clock and conduct the insertion sorting
    startClock = clock();
    // sorting code goes here
    int k = 0;
    for(int i = 1; i < size; i++){
    int selected = values[i];
      for(k = i - 1; k >= 0; k--){
        comps++;
          if(values[k] > selected){
            values[k+1] = values[k];
          } else {
            swaps++;
            break;
          } 
      }
    values[k+1] = selected;
    swaps++;
    }

    elapsedTime = clock() - startClock;
    cout << "Fast Insertion sort completed. Is sorted: " << boolalpha <<
        isSorted(values, size) << endl;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
        << " seconds" << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Comps: " << comps << endl << endl;
}

