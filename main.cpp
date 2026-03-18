#include <iostream>
#include <vector>
#include <chrono>
#include <numeric> // for std::accumulate

// Include your helper headers
#include "utils.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"

// Helper to print trial results
void printResult(const std::string& algo, int size, int trial, double time) {
    std::cout << algo
              << " | Size: " << size
              << " | Trial: " << trial
              << " | Time: " << time << " ms"
              << std::endl;
}

// Helper to run a sorting algorithm for 10 trials and return the average time
template<typename SortFunc>
double runTrials(const std::string& algoName, int size, SortFunc sortFunc, const std::vector<int>& baseArray) {
    std::vector<double> trialTimes;

    for (int trial = 1; trial <= 10; ++trial) {
        std::vector<int> arrCopy = baseArray; // work on a copy
        auto start = std::chrono::high_resolution_clock::now();
        sortFunc(arrCopy);
        auto end = std::chrono::high_resolution_clock::now();

        double ms = std::chrono::duration<double, std::milli>(end - start).count();
        trialTimes.push_back(ms);
        printResult(algoName, size, trial, ms);
    }

    // Compute average
    double avg = std::accumulate(trialTimes.begin(), trialTimes.end(), 0.0) / trialTimes.size();
    std::cout << algoName << " | Size: " << size << " | Average Time: " << avg << " ms\n";
    std::cout << "----------------------------------------\n";
    return avg;
}

int main() {
    std::vector<int> arraySizes = {50000, 100000, 500000, 1000000, 5000000, 10000000};

    for (int size : arraySizes) {
        std::cout << "\n==============================\n";
        std::cout << "Array Size: " << size << std::endl;
        std::cout << "==============================\n";

        // Generate base random array
        std::vector<int> baseArray = generateRandomArray(size);

        // Bubble Sort (skip if too large)
        //runTrials("BubbleSort   ", size, runBubbleSort, baseArray);

        // Insertion Sort (skip if too large)
        //runTrials("InsertionSort", size, runInsertionSort, baseArray);

        // Selection Sort (skip if too large)
        //runTrials("SelectionSort", size, runSelectionSort, baseArray);

        // Merge Sort
        runTrials("MergeSort    ", size, runMergeSort, baseArray);

        // Quick Sort
        runTrials("QuickSort    ", size, runQuickSort, baseArray);

        // Heap Sort
        runTrials("HeapSort     ", size, runHeapSort, baseArray);
    }

    std::cout << "\nAll benchmarks completed.\n";
    std::cout << "Press ENTER to exit...";
    std::cin.get();

    return 0;
}