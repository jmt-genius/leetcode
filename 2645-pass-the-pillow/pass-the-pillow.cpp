class Solution {
public:
    int passThePillow(int n, int time) {
        
        int f= time/(n-1);
        int e=time%(n-1);
        if(f%2==0){
            return e+1;
        }
        else{
            return n-e;
        }
        
    }
};