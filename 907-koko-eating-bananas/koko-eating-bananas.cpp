class Solution {
public:
    long long total(vector<int> &piles,int n){
        long long t=0;
        for(int i=0;i<piles.size();i++){
            t+=ceil((double)piles[i]/n);
        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(total(piles,mid)<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};