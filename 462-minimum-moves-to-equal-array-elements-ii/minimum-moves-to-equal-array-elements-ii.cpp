class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mid = nums.size() / 2;
        int medium = nums[mid];

        int ans = 0;

        for (int x : nums) {
            ans += abs(x - medium);
        }

        return ans;
    }
};