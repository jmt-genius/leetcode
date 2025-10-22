class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0;
        for(int i=0;i<k;i++) lsum+=cardPoints[i];
        int rsum=0;
        int result=lsum;
        int r=n-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[r];
            r--;
            int temp=lsum+rsum;
            result=max(result,temp);
        }
        return result;
    }
};