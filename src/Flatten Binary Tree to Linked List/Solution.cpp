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
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        vector<TreeNode*> vec;
        DFS(root, vec);
        for(int i = 0;i<vec.size()-1;i++){
            vec[i]->left=NULL;
            vec[i]->right = vec[i+1];
        }
        vec[vec.size()-1]->left = NULL;
        vec[vec.size()-1]->right = NULL;
        return;
    }
    void DFS(TreeNode* root, vector<TreeNode*> &vec){
        vec.push_back(root);
        if(root->left!=NULL)
            DFS(root->left, vec);
        if(root->right!=NULL)
            DFS(root->right, vec);
        return;
    }
};