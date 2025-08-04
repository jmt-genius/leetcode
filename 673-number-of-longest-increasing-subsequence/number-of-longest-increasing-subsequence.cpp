class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),cur(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i]=dp[prev]+1;
                    cur[i]=cur[prev];
                }
                else if(nums[prev]<nums[i] && 1+dp[prev]==dp[i]){
                    cur[i]+=cur[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int r=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                r+=cur[i];
            }
        }
        return r;

    }
};