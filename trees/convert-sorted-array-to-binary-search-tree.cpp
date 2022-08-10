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
    TreeNode* recur(vector<int> nums, int st, int end){
       if(st>end){
           return nullptr;
       }
        int mid = (st)+((end-st)/2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = recur(nums,st,mid-1);
        root->right = recur(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       
        return recur(nums,0,nums.size()-1);
    }
};
