
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;

        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }

        sort(squares.begin(), squares.end(), greater<long long>());

        long long score = 0;

        for (int i = 0; i < squares.size(); i++) {
            if (i < (squares.size() + 1) / 2)
                score += squares[i];
            else
                score -= squares[i];
        }

        return score;
    }
};
