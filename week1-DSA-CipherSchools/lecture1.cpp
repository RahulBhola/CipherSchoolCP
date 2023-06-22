#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> merged(m + n);  // Create a new vector to store merged elements
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            merged[k] = nums1[i];
            i--;
        } else {
            merged[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (j >= 0) {
        merged[k] = nums2[j];
        k--;
        j--;
    }
    while (i >= 0) {
        merged[k] = nums1[i];
        k--;
        i--;
    }
    return merged;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int m, n;
        cin >> m >> n;
        vector<int> arr1(m);
        vector<int> arr2(n);
        for (int i = 0; i < m; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        cout << "Before Merging two arrays:" << endl;
        for (int num : arr1) {
            cout << num << " ";
        }
        cout << endl;

        vector<int> merged = mergeSortedArrays(arr1, m, arr2, n);

        cout << "Array after merging: ";
        for (int num : merged) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
