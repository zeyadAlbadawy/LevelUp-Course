class Solution {
public:
    bool canPlaceQueen(vector<vector<char>> &matrix, int n, int i, int j) {
        // Col Check
        int x = i, y = j;
        for(int i = 0; i < x; i++ ) {
            if(matrix[i][j] == 'Q')
              return false;
        }
        // Left Diagonal Check
        x = i;
        y = j;
        while(x >= 0 && y >= 0) {
            if(matrix[x][y] == 'Q') 
               return false;
            x--;
            y--;
        }

        // Right Diagonal Check
        x = i;
        y = j;
        while(y < n && x >= 0) {
            if(matrix[x][y] == 'Q')
              return false;
            y++;
            x--;
        }
        return true;
    }

    void createNewBoard(vector<vector<char>> &matrix,vector<vector<string>> &finalRes, vector<string> &res, int n, int i ) {
        string str;
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if(matrix[x][y] != 'Q')
                   str.push_back('.');
                else str.push_back('Q');
            }
            res.push_back(str);
            str.clear();
        }
        finalRes.push_back(res);
        res.clear();
    }

    void getNQueens(vector<vector<char>> &matrix,vector<vector<string>> &finalRes, vector<string> &res, int n, int i ) {
        // Base Case
        if(i == n) {
            createNewBoard(matrix, finalRes, res, n, i);
            return;
        }

        // Recursive Case
        for(int j = 0; j < n; j++) {
            if(canPlaceQueen(matrix,n ,i, j)) {
                matrix[i][j] = 'Q';
                getNQueens(matrix ,finalRes ,res ,n , i + 1);
            }
            matrix[i][j] = '.';
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> matrix(n, vector<char>(n));
        vector<vector<string>> finalRes;
        vector<string> res;
        getNQueens(matrix, finalRes, res, n, 0);
        return finalRes;
    }
};
