class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> p;
        string r;
        for( char c:s){
            if (c=='('){
                p.push(r.length());
            }
            else if(c==')'){
                int st=p.top();
                p.pop();
                reverse(r.begin()+st,r.end());
            }
            else{
                r+=c;
            }
        }
        return r;
    }
};