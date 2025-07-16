class Solution {
public:
    int lis(int i,int prev,vector<int> &nums,vector<vector<int>> &dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int len=lis(i+1,prev,nums,dp);
        if(prev==-1 || nums[i]>nums[prev]){
            len=max(len,1+lis(i+1,i,nums,dp));
        }
        return dp[i][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return lis(0,-1,nums,dp);
        
    }
};