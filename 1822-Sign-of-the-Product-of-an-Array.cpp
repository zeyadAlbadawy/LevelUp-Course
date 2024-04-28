class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long int product = 1;
        for(auto elm : nums) {
            if(elm == 0) return 0;
            else if(elm > 0) product *= 1;
            else if(elm < 0) product *= -1;
        }

        return product;
    }
};