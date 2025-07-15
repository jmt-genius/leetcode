class Solution {
public:
    int f(int i,int buy,int fee,vector<int> &prices,vector<vector<int>> &dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+f(i+1,0,fee,prices,dp),f(i+1,1,fee,prices,dp));
        }
        else{
            profit=max(-fee+prices[i]+f(i+1,1,fee,prices,dp),f(i+1,0,fee,prices,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,1,fee,prices,dp);
    }
};