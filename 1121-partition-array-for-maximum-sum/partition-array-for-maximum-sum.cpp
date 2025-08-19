class Solution {
public:
    int f(int i,int n,int k,vector<int> &arr,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=-1e9;
        int m=arr[i];
        for(int j=i;j<n;j++){
            if((j-i)+1>k) break;
            m=max(m,arr[j]);
            int cost=m*((j-i)+1)+f(j+1,n,k,arr,dp);
            maxi=max(maxi,cost);
        }
        return dp[i]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,n,k,arr,dp);
    }
};