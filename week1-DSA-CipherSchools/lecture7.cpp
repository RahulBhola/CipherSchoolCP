#include <bits/stdc++.h>
using namespace std;

// Question 1: Sort Colors
void sort012(vector<int> &nums)
{
    int p0 = 0, p1 = 0, p2 = nums.size() - 1;
    while (p1 <= p2)
    {
        switch (nums[p1])
        {
        case 0:
            swap(nums[p0], nums[p1]);
            p0++;
            p1++;
            break;

        case 1:
            p1++;
            break;

        case 2:
            swap(nums[p1], nums[p2]);
            p2--;
            break;

        default:
            break;
        }
    }
}

// int main()
// {
//     int t;
//     cin >> t;
//     while (t-- > 0)
//     {
//         int n;
//         cin >> n;
//         vector<int> v(n);
//         for (auto &i : v)
//             cin >> i;

//         sort012(v);

//         // Print the sorted output
//         for (auto num : v)
//             cout << num << " ";
//         cout << endl;
//     }
//     return 0;
// }

// Question 2
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        bool flag1 = false, flag2 = false;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
                flag1 = true;
        }
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == 0)
                flag2 = true;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (flag1 == true)
        {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
        if (flag2 == true)
        {
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }
    }
};

// int main()
// {
//     int t;
//     cin >> t;
//     while (t-- > 0)
//     {
//         int m, n;
//         cin >> m >> n;
//         vector<vector<int>> mat(m);
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cin >> mat[i][j];
//             }
//         }
//         Solution ob;
//         ob.setZeroes(mat);

//         // Printing the resultant
//         cout << "\n";
//         for (auto row : mat)
//         {
//             for (auto col : mat)
//             {
//                 cout << col << " ";
//             }
//             cout << endl;
//         }
//     }
//     return 0;
// }

// Question 3
class Solution {
public:
    // O(m+n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0,c=matrix[0].size()-1;
        while(c>=0 && r<matrix.size()){
            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c]<target)    r++;
            else c--;
        }
        return false;
    }
};

// Question 4
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums,0,nums.size()-1,target);
    }
    int search(vector<int>& nums,int start,int end, int target) {
        if(start>end)   return -1;
        int mid=start+(end-start)/2;
        if(nums[mid]==target)   return mid;
        //first half or second half
        if(nums[start]<=nums[mid]){
            // 1. first half is sorted 
            // 2. second half has pivot
            if(nums[start]<=target && target<nums[mid]){
                // Element is in the sorted section or array
                return search(nums,start,mid-1,target);
            }
            else{
                // Element is in the non-sorted section or array
                return search(nums,mid+1,end,target);
            }
        }
        else{
            // 1. second half is sorted 
            // 2. first half has pivot
            if(nums[mid]<target && target<=nums[end]){
                // Element is in the sorted section or array
                return search(nums,mid+1,end,target);
            }
            else{
                // Element is in the non-sorted section or array
                return search(nums,start,mid-1,target);
        }
        }
        return -1;
    }
};