class Solution {
public:
    void findSubsets(vector<vector<int>> &finalRes, vector<int> res, int i, vector<int> nums) {
        if(i == nums.size()) {
            finalRes.push_back(res);
            return;
        }
        // Forward Direction
        res.push_back(nums[i]);
        findSubsets(finalRes, res, i+1, nums);
        // BackWard Direction
        res.pop_back();
        findSubsets(finalRes, res, i+1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> finalRes;
        vector<int> res;
        findSubsets(finalRes, res, 0, nums);
        return finalRes;
    }
};
