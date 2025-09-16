class Solution {
public:
    int days(vector<int> &arr,int m,int k,int d){
        int c=0;
        int b=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=d) c++;
            else c=0;
            if(c==k){
                c=0;
                b++;
            }
        }
        if(b>=m) return 1;
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int temp=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(days(bloomDay,m,k,mid)==1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(low>temp) return -1;
        return low;
    }
};