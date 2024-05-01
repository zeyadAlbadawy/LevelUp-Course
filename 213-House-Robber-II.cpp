class Solution {
public:
    int getMaxSum(vector<int> &nums, int start, int end) {
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        if (end - start > 0)
            dp[1] = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i <= end; i++) {
            dp[i - start] = max(dp[i - start - 1], dp[i - start - 2] + nums[i]);
        }
        return dp[dp.size() - 1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        int max1 = getMaxSum(nums, 0, nums.size() - 2);
        int max2 = getMaxSum(nums, 1, nums.size() - 1);
        
        return max(max1, max2);
    }
};
