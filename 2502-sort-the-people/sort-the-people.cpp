class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mapi;
        int n=names.size();
        for(int i=0;i<n;i++){
            mapi[heights[i]]=names[i];
        }
        sort(heights.begin(),heights.end());
        vector<string> s(n);
        for(int i=n-1;i>=0;i--){

            s[n-i-1]=mapi[heights[i]];
        }
        return s;
    }
    
};