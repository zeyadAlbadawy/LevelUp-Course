class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> inc, dec;
        int maxLength = 0, left = 0;
        for(int i = 0; i < nums.size(); i++) {
            // Checking The Increasing Deque
            while(inc.size() > 0 && nums[i] < inc.back())
               inc.pop_back();
            inc.push_back(nums[i]);

            // Checking The Decreasing Deque
            while(dec.size() > 0 && nums[i] > dec.back())
              dec.pop_back();
            dec.push_back(nums[i]);

            while(dec.front() - inc.front() > limit) {
                if(dec.front() == nums[left])
                   dec.pop_front();
                if(inc.front() == nums[left])
                  inc.pop_front();
                left++;
            }
            maxLength = max(maxLength, i - left + 1);
        }
        return maxLength;
    }
};