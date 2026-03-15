#include "bubble_sort.h"
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr)
{
    int n = arr.size();

    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

double runBubbleSort(const vector<int>& input)
{
    vector<int> arr = input;   // copy array

    auto start = high_resolution_clock::now();

    bubbleSort(arr);

    auto end = high_resolution_clock::now();

    duration<double> elapsed = end - start;

    return elapsed.count();
}