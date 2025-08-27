/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> st;
        st.push(root);
        while(!st.empty()){
            int s=st.size();
            for(int i=0;i<s;i++){
                Node* node=st.front();
                st.pop();
                if(i==s-1){
                    node->next=NULL;
                }
                else{
                    node->next=st.front();
                }
                if(node->left) st.push(node->left);
                if(node->right) st.push(node->right);
                
            }
        }
        return root;

        
    }
};