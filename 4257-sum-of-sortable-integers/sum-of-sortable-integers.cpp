
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int start = 0; start < n && ok; start += k) {
                int descents = 0;

                for (int j = start; j < start + k - 1; j++) {
                    if (nums[j] > nums[j + 1]) {
                        descents++;
                    }
                }

                // A block can be rotated into sorted order
                // if it has at most one descent, including wraparound.
                if (k > 1 && nums[start + k - 1] > nums[start]) {
                    descents++;
                }

                if (descents > 1) {
                    ok = false;
                    break;
                }

                vector<int> block(nums.begin() + start,
                                  nums.begin() + start + k);
                vector<int> target(sorted.begin() + start,
                                   sorted.begin() + start + k);

                sort(block.begin(), block.end());
                sort(target.begin(), target.end());

                if (block != target) ok = false;
            }

            if (ok) ans += k;
        }

        return (int)ans;
    }
};
