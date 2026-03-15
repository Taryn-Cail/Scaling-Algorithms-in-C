#include "heap_sort.h"
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr)
{
    int n = arr.size();

    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

double runHeapSort(const vector<int>& input)
{
    vector<int> arr = input;

    auto start = high_resolution_clock::now();

    heapSort(arr);

    auto end = high_resolution_clock::now();

    duration<double> elapsed = end - start;

    return elapsed.count();
}