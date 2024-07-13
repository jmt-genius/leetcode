class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int r=0;
        string h= x>y? "ab" : "ba";
        string l=h=="ab"?"ba":"ab";
        string af=remove(s,h);
        int rcc=(s.length()-af.length())/2;
        r+=rcc*max(x,y);
        string aff=remove(af,l);
        rcc=(af.length()-aff.length())/2;
        r+=rcc*min(x,y);
        return r;
        

    }
private:
    string remove(const string& input,const string& p){
        stack<char> st;

        for(char cc:input){
            if(cc==p[1] && !st.empty() && st.top()==p[0]){
                st.pop();
            }else{
                st.push(cc);
            }
        }
        string rc;
        while(!st.empty()){
            rc+=st.top();
            st.pop();

        }
        reverse(rc.begin(),rc.end());
        return rc;

    }
};