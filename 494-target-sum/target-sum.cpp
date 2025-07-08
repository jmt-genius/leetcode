class Solution {
public:
    int f(int ind, int count, int t, vector<int>& nums, vector<vector<int>>& dp, int offset) {
        if (ind == 0) {
            int plus = count + nums[ind];
            int minus = count - nums[ind];
            int ways = 0;
            if (plus == t) ways++;
            if (minus == t) ways++;
            return ways;
        }
        if (dp[ind][count + offset] != -1) return dp[ind][count + offset];

        int plus = f(ind - 1, count + nums[ind], t, nums, dp, offset);
        int minus = f(ind - 1, count - nums[ind], t, nums, dp, offset);
        return dp[ind][count + offset] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // If target is not in range [-sum, sum], return 0
        if (abs(target) > sum) return 0;

        int offset = sum;  // to handle negative indices
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
        return f(n - 1, 0, target, nums, dp, offset);
    }
};
