class Solution {
public:
    int f(int i,int buy,int count,int n,vector<int> &prices,vector<vector<vector<int>>> &dp,int k){
        if(count==k) return 0;
        if(i==n) return 0;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+f(i+1,0,count,n,prices,dp,k),f(i+1,1,count,n,prices,dp,k));
        }
        else{
            profit=max(prices[i]+f(i+1,1,count+1,n,prices,dp,k),f(i+1,0,count,n,prices,dp,k));
        }
        return dp[i][buy][count]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return f(0,1,0,n,prices,dp,k);
    }
};