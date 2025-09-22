class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        int c=0;
        int l=0,r=0;
        int maxlen=0;
        while(r<nums.size()){
            if(nums[r]==0){
                if(k==0){
                    l=r+1;
                }
                else if(q.size()==k){
                    int f=q.front();
                    q.pop();
                    l=f+1;
                    q.push(r);
                }
                else{
                    q.push(r);
                }
            }
            int len=r-l+1;
            maxlen=max(len,maxlen);
            r++;
        }
        return maxlen;
    }
};