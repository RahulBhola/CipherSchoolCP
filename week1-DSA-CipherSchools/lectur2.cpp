#include <bits/stdc++.h>
using namespace std;

// // Iterative Approach
// vector<int> firstAndLastOccurrence(vector<int>& nums, int target) {
//     int first=-1;
//     int last=-1;
//     int n=nums.size();
//     for(int i=0;i<n;i++){
//         if(nums[i]!=target){
//             continue;
//         }
//         else if(first==-1){
//             first=i;
//             last=i;
//         }
//         else{
//             last=i;
//         }   
//     }
//     if(first!=-1){
//         return {first,last};
//     }
//     return {-1,-1};
// }

// Recursive Approach
int firstOccurrence(vector<int> &nums, int start, int end, int target) {
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target))
        return mid;
    else if (nums[mid] < target)
        return firstOccurrence(nums, mid + 1, end, target);
    else
        return firstOccurrence(nums, start, mid - 1, target);
}

int lastOccurrence(vector<int> &nums, int start, int end, int target) {
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] > target))
        return mid;
    else if (nums[mid] > target)
        return lastOccurrence(nums, start, mid - 1, target);
    else
        return lastOccurrence(nums, mid + 1, end, target);
}

vector<int> firstAndLastOccurrence(vector<int> &nums, int target) {
    int first = firstOccurrence(nums, 0, nums.size() - 1, target);
    int last = lastOccurrence(nums, 0, nums.size() - 1, target);
    return {first, last};
}

int main(){
    int t;
    cin >> t;
    while (t-- > 0) {
        int m;
        cin >> m;
        vector<int> arr1(m);
        for (int i = 0; i < m; i++) {
            cin >> arr1[i];
        }
        int x;
        cin>>x;

        vector<int> occurrences = firstAndLastOccurrence(arr1,x);

        cout << "First occurrence: " << occurrences[0] << endl;
        cout << "Last occurrence: " << occurrences[1] << endl;
    }
    return 0;
}