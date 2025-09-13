class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> ans={0,0,0,0,0};
        map<pair<long long,long long>,bool> mp;

        for(auto i: coordinates){
            mp[{i[0],i[1]}]=1;
        }
        vector<int> dx[4]={{0,-1,-1,0},{0,-1,-1,0},{0,1,1,0},{0,1,1,0}};
        vector<int> dy[4]={{0,-1,0,-1},{0,1,0,1},{0,1,0,1},{0,-1,0,-1}};
        int a;
        for(auto cor:coordinates){
            for(int k=0;k<4;k++){
               a=0;
               for(int i=0;i<4;i++){
                long long cx=cor[0]+dx[k][i];
                long long cy=cor[1]+dy[k][i];
                if(cx<0 || cy<0 || cx>=m || cy>=n){ a=5; break;}
                if(mp.find({cx,cy})!=mp.end()){
                    a++;
                }
               }
               if(a<5){
                 ans[a]++;
               }
            }
        }

        for(int i=1;i<=4;i++){
            ans[i]=ans[i]/i;
        }
        ans[0]=(long long)(m-1)*(long long)(n-1) -accumulate(ans.begin()+1,ans.end(),0);
        return ans;
    }
};