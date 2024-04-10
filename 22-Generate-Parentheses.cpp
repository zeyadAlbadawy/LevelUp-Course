static const auto _ = []() noexcept {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    void generateParanthesis(vector<string> &resV, int open, int closed, int n, string finalS) {
        // Base Case
        if(finalS.size() == 2*n) {
            resV.push_back(finalS);
            return;
        }
        // Checking For Open Bracket Conition
        if(open < n) 
           generateParanthesis(resV, open+1, closed, n, finalS + '(');
        
        // Checking For Closed Bracket Condition
        if(closed < open) 
            generateParanthesis(resV, open, closed + 1, n, finalS + ')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> resV;
        string finalS;
        generateParanthesis(resV, 0, 0, n, finalS);
        return resV;
    }
};