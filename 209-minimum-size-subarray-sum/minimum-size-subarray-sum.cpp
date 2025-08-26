class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int sum=0;
        int mini=1e9;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=target){
                mini=min(mini,(right-left)+1);
                sum-=nums[left];
                left++;
            }
        }
        return mini==1e9?0:mini;
        
    }
};