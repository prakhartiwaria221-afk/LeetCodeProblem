
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        vector<vector<int>> right(m, vector<int>(n, -1));
        vector<vector<int>> down(m, vector<int>(n, -1));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (grid[i][j] == 0)
                    continue;
                int ni = i + 1;
                int nj = j;

                if (ni < m) {
                    if (grid[ni][nj] == 0)
                        right[i][j] = ni * n + nj;
                    else
                        right[i][j] = down[ni][nj];
                }
                ni = i;
                nj = j + 1;

                if (nj < n) {
                    if (grid[ni][nj] == 0)
                        down[i][j] = ni * n + nj;
                    else
                        down[i][j] = right[ni][nj];
                }
            }
        }

        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0)
                    continue;
                if (j + 1 < n) {
                    int ni = i;
                    int nj = j + 1;

                    int dest;

                    if (grid[ni][nj] == 0)
                        dest = ni * n + nj;
                    else
                        dest = right[ni][nj];

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;

                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                    }
                }
                if (i + 1 < m) {
                    int ni = i + 1;
                    int nj = j;

                    int dest;

                    if (grid[ni][nj] == 0)
                        dest = ni * n + nj;
                    else
                        dest = down[ni][nj];

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;

                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
