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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int mini=q.front().second;
            int s=q.size();
            int first,last;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front().first;
                int cur=q.front().second-mini;
                q.pop();
                if(i==0) first=cur;
                if(i==s-1) last=cur;
                if(node->left) q.push({node->left,(long long)cur*2+1});
                if(node->right) q.push({node->right,(long long)cur*2+2});

            }
            ans=max(ans,(last-first)+1);
        }
        return ans;
    }
};