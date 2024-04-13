static const auto _ = []() noexcept {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
void performSorting(vector<int> &nums, int start, int end) {
    int i = start;
    int mid = (start + end) / 2;
    int j = mid + 1;
    vector<int> tempArray;

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j])
            tempArray.push_back(nums[i++]);
        else
            tempArray.push_back(nums[j++]);
    }

    while (i <= mid)
        tempArray.push_back(nums[i++]);
    while (j <= end)
        tempArray.push_back(nums[j++]);

    for (int k = start; k <= end; ++k)
        nums[k] = tempArray[k - start];
}

void mergeSort(vector<int> &nums, int start, int end) {
    if (start >= end) {
        return;
    }
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        performSorting(nums, start, end);
}


    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0 ,nums.size() - 1);
        return nums;
    }
};
