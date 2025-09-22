class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int> hash(256,-1);
        int r=0,l=0,maxlen=0;
        while(r<n){
            if(hash[(int)s[r]]!=-1){
                if(hash[(int)s[r]]>=l){
                    l=hash[(int)s[r]]+1;
                }
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            hash[(int)s[r]]=r;
            r++;
        }
        return maxlen;
        
    }
};