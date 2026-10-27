class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        int i = 0, j = 0;
        while (i < m && j < n) {
            grid[i][j] = '.';

            if (i == m - 1) {
                j++;
            } else if (j == n -1){
                i++;
            } else {
                grid[i][j + 1] = '.';
                j++;
                grid[i][j] = '.';
                i++;
            }
        }

        return grid;
        
    }
};