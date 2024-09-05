class Solution {
public:
    vector<int> gen(int n){
        vector<int> r;
        r.push_back(1);
        int ans=1;
        for(int i=1;i<n;i++){
            ans=ans*(n-i);
            ans=ans/i;
            r.push_back(ans);
        }
        return r;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=1;i<=numRows;i++){
            res.push_back(gen(i));
        }
        return res;
    }
};