#include <iostream>
#include <vector>
using namespace std;

// q1: generate Parenthesis leetcode
void generateParenthesis(string& strSoFar, vector<string>& result, int open, int close) {
    if (open<0 || close<0 || open > close) {
        return;
    }
    else if (open == 0 && close == 0) {
        result.push_back(strSoFar);
        return;
    }
    else if(open<=close){
        // Next recursion
        strSoFar.push_back('(');
        generateParenthesis(strSoFar, result, open - 1, close);
        strSoFar.pop_back();

        strSoFar.push_back(')');
        generateParenthesis(strSoFar, result, open, close - 1);
        strSoFar.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    int open = n, close = n;
    string strSoFar = "";
    generateParenthesis(strSoFar, result, open, close);
    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<string> res = generateParenthesis(n);

    cout << "All combinations of parentheses with " << n << " pairs:\n";
    for (const string& str : res) {
        cout << str << "\n";
    }

    return 0;
}


// q2: Letter pphone key leetcode
class Solution {
public:
    void dfs(string s, int i, vector<string> &ans,vector<string> &alpha, string str){
        if(i>=s.size()){
            ans.push_back(str);
            return;
        }
        for(int j=0;j<alpha[s[i]-'0'].size();j++){
            dfs(s,i+1,ans,alpha,str+alpha[s[i]-'0'][j]);
        }
        return ;
    }
    vector<string> letterCombinations(string digits){
        vector<string> ans;
        vector<string> alpha={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string str;
        dfs(digits,0,ans,alpha,str);
        return ans;
    }
};

// q3: permutation
class Solution {
public:
    void solve(int i,int &n,vector<int> &v,vector<vector<int>> &ans){
        if(i>=n-1){
            ans.push_back(v);
            return;
        }
        for(int j = i; j < n; j++){
            swap(v[i],v[j]);
            solve(i+1,n,v,ans);
            swap(v[i],v[j]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(0,n,nums,ans);
        return ans;
    }
};

// q4: power set
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