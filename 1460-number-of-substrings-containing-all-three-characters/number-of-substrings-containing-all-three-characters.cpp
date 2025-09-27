class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> mpp(3,-1);
        int l=0,r=0,sum=0;
        while(r<s.size()){
            mpp[(int)s[r]-'a']=r;
            int mini=*min_element(mpp.begin(),mpp.end());
            if(mini!=-1){
                sum+=mini+1;
            }
            r++;
        }
        return sum;
    }
};