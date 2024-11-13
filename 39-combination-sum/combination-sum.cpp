class Solution {
public:
    void recursive_sum(int ind,int t,vector<int> &arr, vector<vector<int>> &ans,vector<int> &ds){
        if(ind==arr.size()){
            if(t==0){
                ans.push_back(ds);    
            }
            return;
        }
        if(arr[ind]<=t){
            ds.push_back(arr[ind]);
            recursive_sum(ind,t-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        recursive_sum(ind+1,t,arr,ans,ds);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int ind=0;
        recursive_sum(ind,target,candidates,ans,ds);
        return ans;
    }
};