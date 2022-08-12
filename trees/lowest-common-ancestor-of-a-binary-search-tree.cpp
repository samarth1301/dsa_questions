/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res = NULL;
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
         if(!root) return false;
        
      
        int temp = 0;
          if(root == p || root == q){
            temp = 1;
        }
        int l = helper(root->left,p,q) ? 1 : 0;
        int r = helper(root->right,p,q) ? 1 : 0;
        if(l+r+temp>=2){
            res=root;
        }
        return l+r+temp>0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       helper(root,p,q);
        return res;
    }
};
