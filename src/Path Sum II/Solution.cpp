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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result = {{}};
        if(root!=NULL)
            DFS(root, result, sum);
        result.pop_back();
        return result;
    }
    void DFS(TreeNode* root, vector<vector<int>> &result, int dest){
        result.back().push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&root->val == dest){
            vector<int> copy = result.back();
            result.insert(result.begin(), copy);
        }
        if(root->left!=NULL)
            DFS(root->left, result, dest-root->val);
        if(root->right!=NULL)
            DFS(root->right, result, dest-root->val);
        result.back().pop_back();
        return;
    }
};