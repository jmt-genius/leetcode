/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int> &preorder,int prest,int preend,vector<int> &inorder,int inst,int inend,map<int,int> &mpp){
        if(prest>preend || inst>inend) return NULL;
        TreeNode* root=new TreeNode(preorder[preend]);
        int inroot=mpp[root->val];
        int numsleft=inroot-inst;
        root->left=buildTree(preorder,prest,prest+numsleft-1,inorder,inst,inroot-1,mpp);
        root->right=buildTree(preorder,prest+numsleft,preend-1,inorder,inroot+1,inend,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i=0;i<postorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
};