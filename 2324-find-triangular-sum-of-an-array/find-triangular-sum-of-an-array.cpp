class Solution {
public:
    int f(vector<int> &nums){
        if(nums.size()==1) return nums[0];
        vector<int> res;
        for(int i=0;i<nums.size()-1;i++){
            res.push_back((nums[i]+nums[i+1])%10);
        }
        return f(res);
    }
    int triangularSum(vector<int>& nums) {
        return f(nums);
    }
};