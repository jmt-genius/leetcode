class Solution {
public:
    int f(int ind,vector<int> &nums,vector<int> &dp){
        if(ind==0){
            return nums[ind];
        }
        if(ind ==-1) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int pick=nums[ind]+f(ind-2,nums,dp);
        int notpick=0+f(ind-1,nums,dp);
        
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=dp[i-2];
            int nottake=0+dp[i-1];
            dp[i]=max(take,nottake); 
        }
        return dp[n-1];
    }
};