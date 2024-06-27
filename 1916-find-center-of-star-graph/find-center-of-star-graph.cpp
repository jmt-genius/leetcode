class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int r;
        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]){
            r= edges[0][0];
        }
        else{
            r=edges[0][1];
        }
        return r;
    }
};