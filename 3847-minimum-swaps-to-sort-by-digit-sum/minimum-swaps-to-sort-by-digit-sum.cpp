
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            arr.push_back({sum, nums[i]});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> position;

        for (int i = 0; i < n; i++) {
            position[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != arr[i].second) {
                swaps++;

                int correctIndex = position[arr[i].second];
                position[nums[i]] = correctIndex;
                position[arr[i].second] = i;

                swap(nums[i], nums[correctIndex]);
            }
        }

        return swaps;
    }
};
