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
    bool isValidBST(TreeNode* root) {
        // if(!root) return true;
        // // bool left= true, right = true;
        return recur( root, LONG_MIN, LONG_MAX);
       
        // if(root->left && root->left->val>=root->val){
        //     return false;
        // } 
        // if(root->right && root->right->val<=root->val){
        //     return false;
        // } 
        // return isValidBST(root->left) && isValidBST(root->right);
    }
    bool recur(TreeNode* root, long min, long max){
        if(root == NULL) return true;
        if((root->val<max) && (root->val>min)){
            return recur(root->left,min,root->val) && recur(root->right,root->val,max);
        }
        else{
            return false;
        }
      
    }
};
