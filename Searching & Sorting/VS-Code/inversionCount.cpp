#include <iostream>
#include <vector>
using namespace std;

int mergeSort(vector<int> &nums, int start, int end) {
    int i = start;
    int mid = start + (end - start) / 2;
    int j = mid + 1;
    int cnt = 0;
    vector<int> tempArray;
    while(i <= mid && j <= end) {
        if(nums[i]  <= nums[j]) {
            tempArray.push_back(nums[i++]);
        } else {
            cnt += (mid - i + 1);
            tempArray.push_back(nums[j++]);
        }
    } 

    while(i <= mid) 
      tempArray.push_back(nums[i++]);
    while(j <= end) 
      tempArray.push_back(nums[j++]);
    
    return cnt;
}

int inversionCount(vector<int> &nums, int start, int end) {
    if(start >= end)
       return 0;
    int mid = start + (end - start) / 2;
    int c1 = inversionCount(nums, start, mid);
    int c2 = inversionCount(nums, mid + 1, end);
    int c3 = mergeSort(nums, start, end);
    return c1 + c2 + c3;
}
int main() {
    vector<int> nums = {0,5,2,3,1};
    cout << inversionCount(nums, 0, nums.size() - 1);
}
