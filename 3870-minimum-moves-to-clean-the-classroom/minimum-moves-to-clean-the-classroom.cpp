
class Solution {
public:
    struct State {
        int r, c, mask, energy, moves;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startR = 0, startC = 0;
        vector<vector<int>> litterId(m, vector<int>(n, -1));
        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                } else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        int target = (1 << litterCount) - 1;
        if (target == 0) return 0;

        int masks = 1 << litterCount;
        vector<int> best(m * n * masks, -1);

        auto getIndex = [&](int r, int c, int mask) {
            return (r * n + c) * masks + mask;
        };

        queue<State> q;
        q.push({startR, startC, 0, energy, 0});
        best[getIndex(startR, startC, 0)] = energy;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            int idx = getIndex(cur.r, cur.c, cur.mask);

            if (cur.energy < best[idx]) {
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int nr = cur.r + dr[k];
                int nc = cur.c + dc[k];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }

                if (classroom[nr][nc] == 'X') {
                    continue;
                }

                if (cur.energy == 0) {
                    continue;
                }

                int newEnergy = cur.energy - 1;
                int newMask = cur.mask;
                int newMoves = cur.moves + 1;

                if (classroom[nr][nc] == 'L') {
                    newMask |= (1 << litterId[nr][nc]);
                }

                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                if (newMask == target) {
                    return newMoves;
                }

                int newIdx = getIndex(nr, nc, newMask);

                if (newEnergy <= best[newIdx]) {
                    continue;
                }

                best[newIdx] = newEnergy;
                q.push({nr, nc, newMask, newEnergy, newMoves});
            }
        }

        return -1;
    }
};
