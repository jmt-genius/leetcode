class Solution {
public:
    void per(int ind, vector<int> nums, vector<vector<int>> &ans,vector<int> &ds){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            per(ind+1,nums,ans,ds);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        per(0,nums,ans,ds);
        return ans;
    }
};