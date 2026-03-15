#include <iostream>
#include <iomanip>
#include <vector>

#include "utils.h"

#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"

using namespace std;

int main()
{
    const int trials = 10;

    vector<int> sizes =
    {
        1000,
        10000,
        50000,
        100000,
        500000,
        1000000
    };

    cout << fixed << setprecision(6);

    cout << "============================================================\n";
    cout << "Sorting Benchmark (Average Time in Seconds)\n";
    cout << "============================================================\n";

    cout << setw(10) << "Size"
         << setw(12) << "Bubble"
         << setw(12) << "Insertion"
         << setw(12) << "Selection"
         << setw(12) << "Merge"
         << setw(12) << "Quick"
         << setw(12) << "Heap" << endl;

    cout << "------------------------------------------------------------\n";

    for(int size : sizes)
    {
        double bubble = 0;
        double insertion = 0;
        double selection = 0;
        double merge = 0;
        double quick = 0;
        double heap = 0;

        for(int t = 0; t < trials; t++)
        {
            vector<int> baseArray = generateRandomArray(size);

            bubble += runBubbleSort(baseArray);
            insertion += runInsertionSort(baseArray);
            selection += runSelectionSort(baseArray);
            merge += runMergeSort(baseArray);
            quick += runQuickSort(baseArray);
            heap += runHeapSort(baseArray);
        }

        bubble /= trials;
        insertion /= trials;
        selection /= trials;
        merge /= trials;
        quick /= trials;
        heap /= trials;

        cout << setw(10) << size
             << setw(12) << bubble
             << setw(12) << insertion
             << setw(12) << selection
             << setw(12) << merge
             << setw(12) << quick
             << setw(12) << heap
             << endl;
    }

    return 0;
}