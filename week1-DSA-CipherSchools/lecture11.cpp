#include <vector>
#include <string>

using namespace std;

// q1: word search
class Solution {
public:
    bool isSafe(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int index, int x, int y, const int& R, const int& C) {
        return (x >= 0 && x < R && y >= 0 && y < C && !visited[x][y] && board[x][y] == word[index]);
    }

    int xMoves[4] = {0, 0, 1, -1};
    int yMoves[4] = {1, -1, 0, 0};

    bool exist(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int idx, int x, int y, const int& R, const int& C) {
        if (idx >= word.size())
            return true;
        else {
            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int nextX = x + xMoves[i];
                int nextY = y + yMoves[i];
                if (isSafe(board, visited, word, idx, nextX, nextY, R, C)) {
                    if (exist(board, visited, word, idx + 1, nextX, nextY, R, C))
                        return true;
                }
            }
            visited[x][y] = false;
            return false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word == "")
            return true;
        int R = board.size();
        if (R == 0)
            return false;
        int C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == word[0] && exist(board, visited, word, 1, i, j, R, C)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// q2: power(x,n)
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)    return 1;
        if(n==1)    return x;
        if(n>0){
            if(n%2 == 0)    return myPow(x*x,n/2);
            else return x*myPow(x*x,n/2);
        }
        else{
            n=abs(n);
            if(n%2 == 0)    return 1/(myPow(x*x,n/2));
            else return 1/(x*myPow(x*x,n/2));
        }
    }
};

// q3: power set
class Solution {
public:
    void subsetFinder(int idx,vector<int> &nums, int n, vector<int> &temp, vector<vector<int>> &ans){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subsetFinder(idx+1,nums,n,temp,ans);
        temp.pop_back();
        subsetFinder(idx+1,nums,n,temp,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        subsetFinder(0,nums,n,temp,ans);
        return ans;
    }
};