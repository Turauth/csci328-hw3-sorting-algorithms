#include "algorithms.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <string>

double timeSum{ 0 };
string sortName{};
vector<vector<double>> timeVectors{ {}, {}, {} };

int main() {

    // Add values from 1-5000 to an array.
    vector<int> a1{};    
    for (int i{ 1 }; i <= LEN; ++i) {
        a1.push_back(i);
    }

    for (int i{ 1 }; i <= 3; ++i) {
        for (int j{ 1 }; j <= 100; ++j) {
            
            shuffleArray(a1);

            // The time recording implementation was initially taken from https://cplusplus.com/reference/ctime/clock/.
            clock_t t{ clock() };

            if (i == 1) {
                a1 = selectionSort(a1);
                sortName = "Selection Sort";                
            }

            if (i == 2) {
                a1 = bubbleSort(a1);
                sortName = "Bubble Sort";
            }

            if (i == 3) {
                quickSort(a1, 0, LEN - 1);
                sortName = "Quick Sort";             
            }

            double time { ((double) clock() - t)/CLOCKS_PER_SEC };
            timeSum = timeSum + time;
            timeVectors[i - 1].push_back(time);

            if (j == 100) {
                double timeAverage{ timeSum/100 };
                cout << sortName << " average time: " << timeAverage << endl;
            }
        }
        timeSum = 0;
    }

    // Open an existing CSV file or make a new one.
    ofstream fout("sortTimes.csv");

    // Write column headers.
    fout << "Selection Sort,Bubble Sort,Quick Sort\n";
    for (int i{ 1 }; i <= 100; ++i) {
        fout << timeVectors[0][i - 1] << ","
             << timeVectors[1][i - 1] << ","
             << timeVectors[2][i - 1] << "\n";
    }
    
    // Close file stream
    fout.close();

    return 0;    
}