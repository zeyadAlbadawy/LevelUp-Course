class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int i, int j, int n, char num) {
        for (int k = 0; k < n; k++) {
            if (board[k][j] == num || board[i][k] == num)
                return false;
        }

        int xA = (i / 3) * 3;
        int yA = (j / 3) * 3;

        for (int xItr = xA; xItr < xA + 3; xItr++) {
            for (int yItr = yA; yItr < yA + 3; yItr++) {
                if (board[xItr][yItr] == num)
                    return false;
            }
        }
        return true;
    }

    bool getSudokuSolver(vector<vector<char>>& board,int i, int j, int n) {
        // Base Case
        if(i == n)
          return true;

        // The End  Of The Colum
        if(j == n)
          return getSudokuSolver(board, i+1, 0 , n);
        
        if(board[i][j] != '.')
          return getSudokuSolver(board, i, j + 1, n);

        for(char num = '1'; num <= '9'; num++) {
            if(canPlace(board, i , j, n, num)) {
                board[i][j] = num;
                bool sedokuPlaced = getSudokuSolver(board, i, j + 1, n);
                if(sedokuPlaced) 
                  return true;
            }
        }
        board[i][j] = '.';
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        getSudokuSolver(board,0 ,0 ,9);
    }
};
