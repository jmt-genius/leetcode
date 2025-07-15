class Solution {
public:
    int f(int i,int buy,vector<int> &prices,vector<vector<int>> &dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        }
        else{
            profit=max(prices[i]+f(i+1,1,prices,dp),f(i+1,0,prices,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        int n=prices.size();
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                 int profit=0;
                if(j){
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][1];

    }
};