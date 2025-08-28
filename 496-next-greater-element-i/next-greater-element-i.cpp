class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp1(nums2.size());
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()) temp1[i]=-1;
            else temp1[i]=st.top();
            st.push(nums2[i]);
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=temp1[find(nums2.begin(),nums2.end(),nums1[i])-nums2.begin()];
        }
        return ans;
        
    }
};