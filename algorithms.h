#pragma once
#include <array>
#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

const int LEN{ 5000 };

void outputArray(vector<int> array) {
    for (int i{ 0 }; i < LEN; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// The shuffling implementation was taken from https://www.geeksforgeeks.org/cpp/how-to-shuffle-a-vector-in-cpp/.
void shuffleArray(vector<int>& array) {

    // Initialize random number generator.
    random_device rd;
    mt19937 g(rd());

    // Shuffle the vector.
    shuffle(array.begin(), array.end(), g);    
}

// This algorithm was derived from pseudocode in lecture slides.
vector<int> selectionSort(vector<int> unsorted) {

    for (int i{ 0 }; i <= LEN - 2; ++i) {
        int minIndex = i;

        for (int j{ i+1 }; j <= LEN - 1; ++j) {
            if (unsorted[j] < unsorted[minIndex]) {
                minIndex = j;
            }
        }
        int tempVal { unsorted[minIndex] };
        unsorted[minIndex] = unsorted[i];
        unsorted[i] = tempVal;
    }
    vector<int> sorted {unsorted};
    return sorted;
}

// This algorithm was derived from pseudocode in lecture slides.
vector<int> bubbleSort(vector<int> unsorted) {

    for (int i{ 0 }; i <= LEN - 2; ++i) {
        for (int j{ 0 }; j <= LEN - 2 - i; ++j) {
            if (unsorted[j] > unsorted[j+1]) {
                int tempVal{ unsorted[j] };
                unsorted[j] = unsorted[j+1];
                unsorted[j+1] = tempVal;
            }
        }
    }    
    vector<int> sorted {unsorted};
    return sorted;
}

// Partition function taken taken from https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/.
int partitionArray(vector<int>& subarray, int low, int high) {

        // Choose the pivot and define lower iterator.
        int pivot{ subarray[high] };
        int i{ low - 1 };

        // Move elements smaller than the pivot.
        for (int j{ low }; j <= high - 1; ++j) {
            if (subarray[j] < pivot) {
                i++;
                swap(subarray[i], subarray[j]);
            }            
        }
        // Swap the pivot to the index immediately after the elements less than it and return its index as the new pivot index.
        swap(subarray[high], subarray[i + 1]);
        return i + 1;        
}

// Quick sort function taken from https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/.
void quickSort(vector<int>& unsorted, int low, int high) {

    if (low < high) {
        // Define the pivot index for the next recursion.
        int pivotIx{ partitionArray(unsorted, low, high) };

        // Define recursions for subarrays containing values smaller than and greater than or equal to the previous pivot.
        quickSort(unsorted, low, pivotIx - 1);
        quickSort(unsorted, pivotIx + 1, high);      
    }
}