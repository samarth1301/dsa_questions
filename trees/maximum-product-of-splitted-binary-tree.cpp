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
long long c=0;
long long mult = INT_MIN;
    void count(TreeNode* root){
        if(!root) return;
        c+= root->val;
        count(root->left);
        count(root->right);
    }
    int recur (TreeNode* root){
        if(!root) return 0;
        int left = recur(root->left),right = recur(root->right);
        mult = max({mult,(c-left)*left,(c-right)*right});
        return left+right+root->val;
    }
    int maxProduct(TreeNode* root) {
        count(root);
        recur(root);
        int mod = 1e9+7;
       return mult%mod;
    }
};
