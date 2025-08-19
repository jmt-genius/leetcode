class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,int n,string &s,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        int mini=1e9;
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(isPalindrome(0,temp.size()-1,temp)){
                int cost=1+f(j+1,n,s,dp);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return f(0,n,s,dp)-1;
    }
};