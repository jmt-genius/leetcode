class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ini=0;

        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0){
                ini=ini+customers[i];
            }
        }
        int max=0;
        for(int i=0;i<customers.size()+1-minutes;i++){
            int p=0;
            for(int k=0;k<minutes;k++){
                if(grumpy[i+k]==1){
                    p+=customers[i+k];
                }

            }
            if(p>max){
                max=p;
            }

        }
        return ini+max;
    }
};