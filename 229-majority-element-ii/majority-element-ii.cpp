class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ct1=0;
        int ct2=0;
        int el1;
        int el2;
        for (int i=0;i<nums.size();i++){
            if(ct1==0 && el2!=nums[i]){
                ct1=1;
                el1=nums[i];
            }
            else if(ct2==0 && el1!=nums[i]){
                ct2=1;
                el2=nums[i];
            }
            else if(el1==nums[i]){
                ct1++;
            }
            else if(el2==nums[i]){
                ct2++;
            }
            else{
                ct1--;
                ct2--;
            }

        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(el1==nums[i]){
                cnt1++;
                }
            else if(el2==nums[i]){
                cnt2++;
            }
        }
        vector<int> r;
        int min=(int)(nums.size()/3) +1;
        if(cnt1>=min){
            r.push_back(el1);
        }
        if(cnt2>=min){
            r.push_back(el2);
        }
        sort(r.begin(),r.end());
        return r;
    }
};