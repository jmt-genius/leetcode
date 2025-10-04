class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int inc=image[sr][sc];
        vector<vector<int>> result=image;
        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            result[row][col]=color;
            for(int i=0;i<4;i++){
                int trow=row+drow[i];
                int tcol=col+dcol[i];
                if(trow>=0 && trow<n && tcol>=0 && tcol <m && image[trow][tcol]==inc && result[trow][tcol]!=color){
                    q.push({trow,tcol});
                }
            }
        }
        return result;
    }
};