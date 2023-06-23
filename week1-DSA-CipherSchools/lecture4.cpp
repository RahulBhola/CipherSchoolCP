#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralMatrix(vector<vector<int>> mat) {
        int sx = 0, sy = 0, ex = mat.size() - 1, ey = mat[0].size() - 1;
        vector<int> result(mat.size() * mat[0].size());
        int ctr = 0;
        while (sx <= ex && sy <= ey) {
            for (int j = sy; j <= ey; j++) {
                result[ctr++] = mat[sx][j];
            }
            sx++;
            for (int i = sx; i <= ex; i++) {
                result[ctr++] = mat[i][ey];
            }
            ey--;
            if (sx <= ex) {
                for (int j = ey; j >= sy; j--) {
                    result[ctr++] = mat[ex][j];
                }
                ex--;
            }
            if (sy <= ey) {
                for (int i = ex; i >= sx; i--) {
                    result[ctr++] = mat[i][sy];
                }
                sy++;
            }
        }
        return result;
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

    Solution s;
    vector<int> res = s.spiralMatrix(arr);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
