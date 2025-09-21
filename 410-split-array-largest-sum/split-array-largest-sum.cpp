class Solution {
public:
    int f(vector<int> &nums,int k,int m){
        int c=1;
        long long maxi=0;
        for(int i=0;i<nums.size();i++){
            if(maxi+nums[i]<=m){
                maxi=maxi+nums[i];
            }
            else{
                c++;
                maxi=nums[i];
            }
        }
        return c;

    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int st=f(nums,k,mid);
            if(st>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};