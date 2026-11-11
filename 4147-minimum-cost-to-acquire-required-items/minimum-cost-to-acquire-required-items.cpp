class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {
        long long a = need1;
        long long b = need2;
        long long ans = a * cost1 + b * cost2;
        long long common = min(a, b);
        long long option2 = common * costBoth
                          + (a - common) * cost1
                          + (b - common) * cost2;
        long long option3 = max(a, b) * costBoth;

        ans = min(ans, min(option2, option3));

        return ans;
    }
};