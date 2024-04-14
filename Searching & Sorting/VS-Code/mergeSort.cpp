#include <iostream>
#include <vector>
using namespace std;

void performSorting(vector<int> &nums, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    vector<int> tempArray;

    // Merge the two sorted halves into tempArray
    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j])
            tempArray.push_back(nums[i++]);
        else
            tempArray.push_back(nums[j++]);
    }

    // Copy the remaining elements from the first half, if any
    while (i <= mid)
        tempArray.push_back(nums[i++]);

    // Copy the remaining elements from the second half, if any
    while (j <= end)
        tempArray.push_back(nums[j++]);

    // Copy sorted elements back to nums array
    for (int k = start; k <= end; ++k)
        nums[k] = tempArray[k - start];

}

void mergeSort(vector<int> &nums, int start, int end) {
    if(start >= end)
      return;
    int mid = start + (end - start) / 2;
    mergeSort(nums,start, mid);
    mergeSort(nums, mid+1, end);
    performSorting(nums, start, mid, end);
}
int main() {
    vector<int> nums = {1,8,0,3,2};
    mergeSort(nums, 0, nums.size() - 1);
    for(auto elm : nums)
       cout << elm << endl;
}