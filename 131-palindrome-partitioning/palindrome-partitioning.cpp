#include <bits/stdc++.h>
#include <cstring>
class Solution {
public:
    void partition(int ind,string s,vector<vector<string>> &ans,vector<string> &ds){
        if(ind==s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=1;i<=s.length()-ind;i++){
            string sub=s.substr(ind,i);
            
            cout<<sub<<endl;
            string rsub=sub;
            reverse(rsub.begin(),rsub.end());
            
            if(sub!=rsub){
                cout<<"na "<<sub<<endl;
                continue;
            }
            ds.push_back(sub);
            partition(ind+i,s,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        int ind=0;
        vector<vector<string>> ans;
        vector<string> ds;
        partition(0,s,ans,ds);
        return ans;
    }
};