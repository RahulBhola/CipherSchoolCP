
// q1: sudoku solver
class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col, char ch){
        for(int j=0; j<9; j++){
            if(board[row][j] == ch) return false;
        }
        for(int i=0; i<9; i++){
            if(board[i][col] == ch) return false;
        }

        int rMin = row - (row%3);
        int cMin = col - (col%3);
        for(int i=rMin; i<rMin+3; i++){
            for(int j=cMin; j<cMin+3; j++){
                if(board[i][j] == ch) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char ch='1'; ch<='9'; ch++){
                        if(check(board,i,j,ch)){
                            board[i][j] = ch;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// q2: Knight tour
class Solution {
public:
    bool solve(int i,int j,int k,int &m,int &n,vector<vector<int>> &g){
        if(i<0||j<0||i>=m||j>=n||g[i][j] != k)return false;
        if(k==m*n-1)return true;
        return solve(i+2,j-1,k+1,m,n,g)||solve(i+2,j+1,k+1,m,n,g)||solve(i-2,j-1,k+1,m,n,g)||solve(i-2,j+1,k+1,m,n,g)||solve(i-1,j-2,k+1,m,n,g)||solve(i-1,j+2,k+1,m,n,g)||solve(i+1,j+2,k+1,m,n,g)||solve(i+1,j-2,k+1,m,n,g);
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int x = 0,m=grid.size(),n=grid[0].size();
        return solve(0,0,0,m,n,grid);
    }
};