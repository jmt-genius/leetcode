class Solution {
public:
    void subset(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        ans.push_back(ds);
        for(int i=ind;i<arr.size();i++){
            if (i != ind && arr[i] == arr[i - 1]) continue;
            ds.push_back(arr[i]);
            subset(i+1,arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        subset(0,nums,ans,ds);
        vector<vector<int>> v(ans.begin(), ans.end());
        return ans;
    }
};