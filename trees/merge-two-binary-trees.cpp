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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //no node of the two exists
        if(!root1 && !root2) return NULL;
        int a = root1 ? root1->val : 0;
        int b = root2 ? root2->val : 0;
        //create a new node for that position
        auto root = new TreeNode(a+b);
        //use recursion to connect later on all nodes
        root->left = mergeTrees(root1 ? root1->left : NULL,root2 ?  root2->left : NULL);
        //the function will give summed up nodes,
        //if node does not exist pass NULL for a single tree
        root->right = mergeTrees(root1 ? root1->right : NULL, root2 ?  root2->right : NULL);
        return root;
    }
};
