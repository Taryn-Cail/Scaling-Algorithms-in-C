#include "insertion_sort.h"
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& arr)
{
    int n = arr.size();

    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

double runInsertionSort(const vector<int>& input)
{
    vector<int> arr = input;

    auto start = high_resolution_clock::now();

    insertionSort(arr);

    auto end = high_resolution_clock::now();

    duration<double> elapsed = end - start;

    return elapsed.count();
}