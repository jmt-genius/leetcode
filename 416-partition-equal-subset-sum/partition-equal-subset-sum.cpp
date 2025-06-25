class Solution {
public:
    bool f(int ind, vector<int> &nums,int t,vector<vector<int>> &dp){
        if(t==0) return true;
        if(ind==nums.size()) return false;
        if(dp[ind][t]!=-1) return dp[ind][t];
        bool pick1=f(ind+1,nums,t,dp);
        bool pick2=false;
        if(t>=nums[ind]) pick2=f(ind+1,nums,t-nums[ind],dp);
        return dp[ind][t]=pick1 || pick2;
    }
    bool canPartition(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0);
        cout<<s;
        if(s%2!=0) return false;
        vector<vector<int>> dp(nums.size(),vector<int>((s/2)+1,-1));
        return f(0,nums,s/2,dp);

    }
};