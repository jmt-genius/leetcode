class Solution {
public:
    int f(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]=1+f(ind1-1,ind2-1,s1,s2,dp);
        else return dp[ind1][ind2]=max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
    }
    int minInsertions(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return n-f(n-1,n-1,s,s2,dp);
        
    }
};