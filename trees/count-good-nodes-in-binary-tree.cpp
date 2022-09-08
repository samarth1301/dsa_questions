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
      int c = 0;
    
    void recur(TreeNode* r,int mx){
        if(!r) return;
        if(r->val>=mx) c++;
        recur(r->left,max(mx,r->val));
        recur(r->right,max(mx,r->val));

    }
      int goodNodes(TreeNode* r) {
        // return r ? goodNodes(r->left, max(ma, r->val)) + goodNodes(r->right, max(ma, r->val)) + (r->val >= ma) : 0;
          // root= r;
          recur(r,-10000);
          return c;
    }
};
