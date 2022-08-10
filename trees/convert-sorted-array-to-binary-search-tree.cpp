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
        //if st>end return null coz there is nothing to add now.
       if(st>end)
           return nullptr;
        //claculate mid.
        int mid = (st)+((end-st)/2);
        //create a new node with the value in the mid index.
        TreeNode* root = new TreeNode(nums[mid]);
        //add to the left and right of the new created nodes new mid values in that section.
        //it can be null if condition overshoots.
        root->left = recur(nums,st,mid-1);
        root->right = recur(nums,mid+1,end);
        //return that value.
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //simply traverse the array searching for its middle and keep adding it in the tree.
        return recur(nums,0,nums.size()-1);
    }
};
