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
    vector<vector<int>> levelOrder(TreeNode* root) {
     if(root==NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> c;
            for(int i=0;i<levelSize;i++){
                auto temp = q.front();q.pop();
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
                c.push_back(temp->val);
            }
            res.push_back(c);
        }
        return res;
    }
};
