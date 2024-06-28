class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector <long long> degree(n,0);
        for(vector<int>& edges: roads){
            degree[edges[0]]++;
            degree[edges[1]]++;

        }
        sort(degree.begin(),degree.end());
        long long v=1;
        long long r=0;
        for(long long d : degree){
            r+=(v*d);
            v++;
        }
        return r;
    }
};