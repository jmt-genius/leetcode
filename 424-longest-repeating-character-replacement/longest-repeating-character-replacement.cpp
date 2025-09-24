class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0,maxf=0;
        vector<int> hash(26,0);
        while(r<s.size()){
            hash[(int)s[r]-'A']++;
            maxf=max(maxf,hash[(int)s[r]-'A']);
            if((r-l+1)-maxf>k){
                hash[(int)s[l]-'A']--;
                
                l++;
            }
            if((r-l+1)-maxf<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;                            

        }
        return maxlen;
    }
};