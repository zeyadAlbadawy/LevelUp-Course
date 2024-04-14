class Solution {
public:

    int getPartition(vector<int> &nums, int start, int end) {
        int pivot = nums[end];
        int i = start - 1;
        for(int j = start; j < end; j++) {
            if(nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        // Return Pivot To Its Correct Position
        swap(nums[i+1], nums[end]);
        return i+1;
    }
    void QuickSort(vector<int> &nums, int start, int end, int newIdx) {
        // Base Case
        if(start >= end) 
          return;

        int p = getPartition(nums, start, end);
        if(p == newIdx)
          return;
        else if(p > newIdx)
           QuickSort(nums, start, p - 1, newIdx);
        else if(p < newIdx)
           QuickSort(nums, p + 1, end, newIdx);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int newIdx = nums.size() - k;
        QuickSort(nums, 0, nums.size() - 1, newIdx); 
        return nums[newIdx];
    }
};