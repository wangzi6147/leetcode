/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if(root==NULL)
            return result;
        vector<vector<TreeNode *> > data;
        vector<TreeNode *> temp;
        temp.push_back(root);
        data.push_back(temp);
        bool done = false;
        while(!done){
            done = true;
            temp.clear();
            for(TreeNode * node:data.back()){
                if(node->left!=NULL){
                    temp.push_back(node->left);
                    done = false;
                }
                if(node->right!=NULL){
                    temp.push_back(node->right);
                    done = false;
                }
            }
            if(!done)
                data.push_back(temp);
        }
        
        for(int i = data.size()-1;i>=0;i--){
            vector<int> intTemp;
            for(TreeNode * node:data[i]){
                intTemp.push_back(node->val);
            }
            result.push_back(intTemp);
        }
        return result;
    }
};