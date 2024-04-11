class Solution {
public:
void swap(int &firstNum, int &secondNum) {
    int temp = firstNum;
    firstNum = secondNum;
    secondNum = temp;
}
    void getPermute(vector<vector<int>> &finalRes, vector<int> &res, int i) {
        if(i == res.size()) {
            finalRes.push_back(res);
            return;
        }

        for(int k = i; k < res.size(); k++) {
            swap(res[k], res[i]);
            getPermute(finalRes, res, i+1);
            swap(res[k], res[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> finalRes;
        getPermute(finalRes, nums, 0);
        return finalRes;
    }
};