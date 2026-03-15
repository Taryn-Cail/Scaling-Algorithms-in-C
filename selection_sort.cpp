#include "selection_sort.h"
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int>& arr)
{
    int n = arr.size();

    for(int i = 0; i < n-1; i++)
    {
        int minIndex = i;

        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;

        swap(arr[i], arr[minIndex]);
    }
}

double runSelectionSort(const vector<int>& input)
{
    vector<int> arr = input;

    auto start = high_resolution_clock::now();

    selectionSort(arr);

    auto end = high_resolution_clock::now();

    duration<double> elapsed = end - start;

    return elapsed.count();
}