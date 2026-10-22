
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = nums[0];
        bool ascending = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (i + k) % n) {
                ascending = false;
                break;
            }
        }

        if (ascending) {
            if (k == 0) return 0;
            return min(n - k, k + 2);
        }
        k = (n - 1 - nums[0] + n) % n;
        bool descending = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (n - 1 - (i + k) % n + n) % n) {
                descending = false;
                break;
            }
        }

        if (descending) {
            return min(k + 1, n - k + 1);
        }

        return -1;
    }
};
