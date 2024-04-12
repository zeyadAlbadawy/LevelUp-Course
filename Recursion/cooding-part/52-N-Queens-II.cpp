class Solution {
public:
    bool canPlaceQueen(vector<vector<int>> &matrix, int n, int i, int j) {
        // Col Check
        int x = i, y = j;
        for(int i = 0; i < x; i++ ) {
            if(matrix[i][j] == 1)
              return false;
        }
        

        // Left Diagonal Check
        x = i;
        y = j;
        while(x >= 0 && y >= 0) {
            if(matrix[x][y] == 1) 
               return false;
            x--;
            y--;
        }

        // Right Diagonal Check
        x = i;
        y = j;
        while(y < n && x >= 0) {
            if(matrix[x][y] == 1)
              return false;
            y++;
            x--;
        }
        return true;
    }
    int solveNQueens(vector<vector<int>> &matrix, int n, int i) {
        // Base Case
        if(i == n) {
            return 1;
        }
        // Recursive Case
        int totalQueens = 0;
        for(int j = 0; j < n; j++) {
            if(canPlaceQueen(matrix, n, i, j)) {
                matrix[i][j] = 1;
                totalQueens += solveNQueens(matrix, n, i+1);
            }
            // BackTracking if i can't place a queen
            matrix[i][j] = 0;
        }
        return totalQueens;
    }
    int totalNQueens(int n) {
        vector<vector<int>> matrix(n, vector<int> (n));              
        return solveNQueens(matrix, n, 0);
    }
};
