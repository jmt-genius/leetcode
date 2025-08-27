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
        TreeNode* root=new TreeNode(preorder[prest]);
        int inroot=mpp[root->val];
        int numsleft=inroot-inst;
        root->left=buildTree(preorder,prest+1,prest+numsleft,inorder,inst,inroot-1,mpp);
        root->right=buildTree(preorder,prest+numsleft+1,preend,inorder,inroot+1,inend,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i=0;i<preorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        
    }
};