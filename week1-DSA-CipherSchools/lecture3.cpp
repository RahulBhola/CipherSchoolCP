#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> transposed(cols, vector<int>(rows));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed[j][i] = matrix[i][j];
            }
        }

        return transposed;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    Solution solution;
    vector<vector<int>> transposed = solution.rotate(arr);

    // Printing the transposed matrix
    for (int i = 0; i < transposed.size(); i++) {
        for (int j = 0; j < transposed[0].size(); j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
