

// q5: rat i Maze
#define POSSIBLE_MOVES 4
int xMoves[]={0,0,1,-1};
int yMoves[]={1,-1,0,0};

bool isSafe(vector<vector<int>> &mat,vector<vector<bool>> &visited, int x, int y, const int &R,const int &C){
    return ((x>=0 && x<R && y>=0 && y<C) && !visited[x][y] && mat[x][y]==1);
}
bool ratInMaze(vector<vector<int>> &mat,vector<vector<bool>> &visited, int x, int y, const int &R,const int &C){
    if(x == R-1 && y==C-1 && mat[R-1][C-1]==1){
        visited[x][y]=true;
        return true;
    }
    if(isSafe(mat,visited,x,y,R,C)){
        visited[x][y]=true;
        for(int i=0;i<POSSIBLE_MOVES;i++){
            int nextX=x+xMoves[i];
            int nextY=y+yMoves[i];
            if(ratInMaaze(mat,visited, nextX, nextY, R, C)){
                return true;
            }
        }
        visited[x][y]=false;
    }
    return false;
}
bool raTInMaze(vector<vector<int>> &mat){
    int R=mat.size();
    if(R==0)    return true;
    int C=mat[0].size();
    vector<vector<bool>> visited(R,vector<bool>(C,false));
    return ratInMaze(mat,visited,0,0,R,C);
}

// q6: n-Queen Problem
class Solution {
public:

    bool checkValid(vector<string> &board, int row, int col, int size){

        // check straight up 
        for(int i = row-1;i>=0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // check diagonals
        for(int i = 1; i<=row; i++){
            if(col-i>=0){
                // left diagonal
                if(board[row-i][col-i] == 'Q'){
                    return false;
                }
            }
            if(col+i <size){
                // right diagonal
                if(board[row-i][col+i] == 'Q'){
                    return false;
                }
            }
        }
        return true;
    }


    void helper(vector<string> &board,vector<vector<string>> &ans, int row, int size){
        if(row == size){
            ans.push_back(board);
            return;
        }

        for(int i = 0; i<size; i++){
            if(checkValid(board, row, i, size)){
                board[row][i] = 'Q';
                helper(board, ans, row+1, size);
                board[row][i] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string str;
        str.append(n, '.');
        vector<string> board(n, str);
        vector<vector<string>> ans;
        helper(board, ans, 0, n);
        return ans;
    }
};

// q7:unique path III
class Solution
{
public:
    int dfs(vector<vector<int>> &g, int i, int j, int s, int t_s)
    {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1)
            return 0;
        if (g[i][j] == 2)
            return s == t_s ? 1 : 0;
        g[i][j] = -1;
        int paths = dfs(g, i + 1, j, s + 1, t_s) + dfs(g, i - 1, j, s + 1, t_s) +
                    dfs(g, i, j + 1, s + 1, t_s) + dfs(g, i, j - 1, s + 1, t_s);
        g[i][j] = 0;
        return paths;
    }
    int uniquePathsIII(vector<vector<int>> &g)
    {
        auto i1 = 0, j1 = 0, t_steps = 0;
        for (auto i = 0; i < g.size(); ++i)
            for (auto j = 0; j < g[0].size(); ++j)
            {
                if (g[i][j] == 1)
                    i1 = i, j1 = j;
                if (g[i][j] != -1)
                    ++t_steps;
            }
        return dfs(g, i1, j1, 1, t_steps);
    }
};
