class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> f;
        for(int num:nums){
            f[num]++;

        }
        sort(nums.begin(),nums.end(),[&](int a, int b){
            if(f[a]==f[b]){
                return a>b;
            }
            return f[a]<f[b];
        });
        return nums;
        
    }
};