#include "quick_sort.h"
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

double runQuickSort(const vector<int>& input)
{
    vector<int> arr = input;

    auto start = high_resolution_clock::now();

    quickSort(arr, 0, arr.size() - 1);

    auto end = high_resolution_clock::now();

    duration<double> elapsed = end - start;

    return elapsed.count();
}