//In this question I learned how to traverse a tree level by level

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
    void average(TreeNode* root, int level , vector<double> &res, vector<double> &count){
        if(!root) return;
        if(level<res.size()){
            res[level]+=root->val;
            count[level]++;
        }
        else{
            res.push_back(root->val);
            count.push_back(1);
        }
        average(root->left,level+1,res,count);
        average(root->right,level+1,res,count);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        //DFS
        // vector<double> res;
        // vector<double> count;
        // average(root,0,res,count);
        // for(int i = 0 ; i <res.size() ; i++){
        //     res[i] = res[i]/count[i];
        // }
        // return res;
        //BFS
        queue<TreeNode*> q;
        vector<double> res;
        q.push(root);
        while(!q.empty()){
            double sum = 0,c = 0;
            queue<TreeNode *> temp;
            while(!q.empty()){
                auto root = q.front();
                q.pop();
                sum+= root->val;
                c++;
                if(root->left){
                    temp.push(root->left);
                }
                if(root->right){
                    temp.push(root->right);
                }
            }
            res.push_back(sum/c);
            q = temp;
        }
        return res;
    }
};
