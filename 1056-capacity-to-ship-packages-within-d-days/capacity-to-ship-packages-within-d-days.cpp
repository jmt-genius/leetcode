class Solution {
public:
    int possible(vector<int> &weights,int days,int c){
        int t=0;
        cout<<t;
        int cur=0;
        for(int i:weights){
            if(cur+i<=c){
                cur+=i;
            }
            else{
                t++;
                cur=i;
            }
        }
        if(cur>0) t++;
        cout<<t;
        if(t<=days) return 1;
        return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(weights,days,mid)==1){
                high=mid-1;
            }
            else{
                low=mid+1;
            
            }

        }
        return low;
    }
};