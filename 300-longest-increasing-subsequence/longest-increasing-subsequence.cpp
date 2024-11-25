class Solution {
public:
    int ling(int ind, int pre, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            return 0;
        }
        if (dp[ind][pre + 1] != -1) return dp[ind][pre + 1];
        int len = ling(ind + 1, pre, nums, dp);
        if (pre == -1 || nums[ind] > nums[pre]) {
            len = max(len, 1 + ling(ind + 1, ind, nums, dp));
        }
        return dp[ind][pre + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); 
        return ling(0, -1, nums, dp);
    }
};
