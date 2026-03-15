#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

// Include your helper headers
#include "utils.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"

int main() {
    // Array sizes to test
    std::vector<int> arraySizes = {1000, 10000, 50000, 100000, 500000, 1000000};

    // Open CSV file
    std::ofstream csvFile("sorting_timings.csv");
    csvFile << "Algorithm,ArraySize,Trial,Time_ms\n";

    // Loop through array sizes
    for (int size : arraySizes) {
        std::cout << "Running benchmarks for array size: " << size << std::endl;

        // Generate base random array
        std::vector<int> baseArray = generateRandomArray(size);

        // Run 10 trials
        for (int trial = 1; trial <= 10; ++trial) {
            std::cout << "  Trial " << trial << "..." << std::endl;

            // Bubble Sort (skip if array is too large)
            if (size <= 100000) {
                std::vector<int> arrCopy = baseArray;
                auto start = std::chrono::high_resolution_clock::now();
                runBubbleSort(arrCopy);
                auto end = std::chrono::high_resolution_clock::now();
                double ms = std::chrono::duration<double, std::milli>(end - start).count();
                csvFile << "BubbleSort," << size << "," << trial << "," << ms << "\n";
            }

            // Insertion Sort (skip if array is too large)
            if (size <= 100000) {
                std::vector<int> arrCopy = baseArray;
                auto start = std::chrono::high_resolution_clock::now();
                runInsertionSort(arrCopy);
                auto end = std::chrono::high_resolution_clock::now();
                double ms = std::chrono::duration<double, std::milli>(end - start).count();
                csvFile << "InsertionSort," << size << "," << trial << "," << ms << "\n";
            }

            // Selection Sort (skip if array is too large)
            if (size <= 100000) {
                std::vector<int> arrCopy = baseArray;
                auto start = std::chrono::high_resolution_clock::now();
                runSelectionSort(arrCopy);
                auto end = std::chrono::high_resolution_clock::now();
                double ms = std::chrono::duration<double, std::milli>(end - start).count();
                csvFile << "SelectionSort," << size << "," << trial << "," << ms << "\n";
            }

            // Merge Sort
            {
                std::vector<int> arrCopy = baseArray;
                auto start = std::chrono::high_resolution_clock::now();
                runMergeSort(arrCopy);
                auto end = std::chrono::high_resolution_clock::now();
                double ms = std::chrono::duration<double, std::milli>(end - start).count();
                csvFile << "MergeSort," << size << "," << trial << "," << ms << "\n";
            }

            // Quick Sort
            {
                std::vector<int> arrCopy = baseArray;
                auto start = std::chrono::high_resolution_clock::now();
                runQuickSort(arrCopy);
                auto end = std::chrono::high_resolution_clock::now();
                double ms = std::chrono::duration<double, std::milli>(end - start).count();
                csvFile << "QuickSort," << size << "," << trial << "," << ms << "\n";
            }

            // Heap Sort
            {
                std::vector<int> arrCopy = baseArray;
                auto start = std::chrono::high_resolution_clock::now();
                runHeapSort(arrCopy);
                auto end = std::chrono::high_resolution_clock::now();
                double ms = std::chrono::duration<double, std::milli>(end - start).count();
                csvFile << "HeapSort," << size << "," << trial << "," << ms << "\n";
            }
        }
    }

    csvFile.close();
    std::cout << "\nAll benchmarks completed. Results saved to sorting_timings.csv\n";

    // Optional: pause to view console output
    std::cout << "Press ENTER to exit...";
    std::cin.get();

    return 0;
}