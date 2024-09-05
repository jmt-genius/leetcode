class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int e;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                e=nums[i];
            }
            else if(e==nums[i]){
                cnt++;

            }
            else{
                cnt--;
            }
        }
        int cnt1=0;
        for(int i=0;i<nums.size();i++){
            if(e==nums[i]){
                cnt1++;
            }
        }
        if(cnt1>(nums.size()/2)){
            return e;
        }
        else{
            return -1;
        }
    }
};