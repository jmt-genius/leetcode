#include <stack> 
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int r=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="./"){
                ;
            }
            else if(logs[i]=="../"){
                if (r != 0) {
                    r--;
                }
            }
            else{
                r++;
            }
        }
        return r;
        
    }
};