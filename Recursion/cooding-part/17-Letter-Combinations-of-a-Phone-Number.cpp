static const auto _ = []() noexcept {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void getLetterCombination(string input, string output, int i, vector<string> &res, vector<string> &keybad) {
        if(input[i] == '\\0') {
            res.push_back(output);
            return;
        }

        int currDigit = input[i] - '0';
        if(currDigit == 0 || currDigit == 1) 
            getLetterCombination(input, output, i+1, res, keybad);
        
        for(int k = 0; k < keybad[currDigit].size(); k++) 
            getLetterCombination(input, output + keybad[currDigit][k], i + 1, res, keybad);

        return;
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> keybad = {\\,\\, \abc\, \def\, \ghi\, \jkl\, \mno\, \pqrs\, \tuv\, \wxyz\};
        string output;
        vector<string> res;
        getLetterCombination(digits, output, 0, res, keybad);
        return res;
    }
};
