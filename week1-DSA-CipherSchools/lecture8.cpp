#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<=2)  return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<nums.size()-2;i++){
            int curr1=nums[i];
            int start=i+1, end=nums.size()-1;

            while(start<end){
                int mid=start+(end-start)/2;
                if(curr1 + nums[start]+nums[end]==0){
                    result.push_back({curr1, nums[start], nums[end]});
                    start++; end--;
                    while(start < end && nums[start-1]== nums[start]){
                        start++;
                    }
                    while(start<end && nums[end]==nums[end+1]){
                        end--;
                    }
                }
                else if(curr1+nums[start]+nums[end] < 0 ){
                    start++;
                }
                else{
                    end--;
                }
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return result;
    }
};
int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int n;
        cin >> n;

        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        Solution ob;
        vector<vector<int>> res = ob.threeSum(v);

        // Printing the resultant
        for(auto row : res) {
            for(auto col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
    }
    return 0;
}







