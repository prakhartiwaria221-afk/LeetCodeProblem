class Solution {
public:
    multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;
    int target;

    void add(int x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }
        balance();
    }

    void remove(int x) {
        auto it = low.find(x);

        if (it != low.end()) {
            sumLow -= x;
            low.erase(it);
        } else {
            it = high.find(x);
            sumHigh -= x;
            high.erase(it);
        }

        balance();
    }

    void balance() {
        while (low.size() > target) {
            int x = *low.rbegin();
            low.erase(prev(low.end()));
            sumLow -= x;

            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < target && !high.empty()) {
            int x = *high.begin();
            high.erase(high.begin());
            sumHigh -= x;

            low.insert(x);
            sumLow += x;
        }
    }

    long long getCost() {
        long long median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        target = (x + 1) / 2;

        vector<long long> cost(n - x + 1);

        // Calculate cost of every window of size x.
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // DP: minimum cost to select j windows
        // from the first i elements.
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};