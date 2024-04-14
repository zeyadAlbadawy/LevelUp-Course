#include <iostream>
#include <vector>
using namespace std;

int getPartition(vector<int> & arr, int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for(int j = start; j < end; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i + 1;
}

void quickSort(vector <int> &arr, int start, int end) {
    // Base Case
    if(start >= end)    
       return;
    // Recursive Case
    int p = getPartition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main() {
    vector <int> arr = {10,5,2,0,7,6,4};
    quickSort(arr, 0, arr.size() - 1);
    for(auto elm : arr) 
       cout << elm << endl;
}