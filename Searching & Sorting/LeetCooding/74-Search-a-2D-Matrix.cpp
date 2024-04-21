class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get The Row which I'll perfrom BinarySearch upon it.
        int r = matrix.size(), c = matrix[0].size();
        if(r == 0) return false;
        int rS = 0, rE = r - 1;
        int mid = 0;
        while(rS <= rE) {
            mid = (rS + rE) / 2;
            if(matrix[mid][0] > target)
               rE = mid - 1;
            else if(matrix[mid][c-1] < target)
              rS = mid + 1;
            else {
                rS = mid;
                break;
            }
        }
        if (rS > rE)
            return false;

        // Apply Binary Search on that row
        int start = 0, end = c -1;
        while(start <= end) {
            mid = (start + end) / 2;
            if(target > matrix[rS][mid])
              start =  mid + 1;
            else if (target < matrix[rS][mid])
              end = mid - 1;
            else
              return true;
        } 

        return false;
    }
};
