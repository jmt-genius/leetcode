class Solution {
public:
    int f(int ind,int t,vector<int> &coins,vector<vector<int>> &dp){
        if(ind==0){
            if(t==0) return 0;
            if(t%coins[ind]==0) return t/coins[ind];
            else return 1e9;
        }
        if(dp[ind][t]!=-1) return dp[ind][t];
        int nottake=0+f(ind-1,t,coins,dp);
        int take=1e9;
        if(coins[ind]<=t) take=1+f(ind,t-coins[ind],coins,dp);
        return dp[ind][t]=min(nottake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int r=f(n-1,amount,coins,dp);
        if(r==1e9) return -1;
        else return r;

    }
};