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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		if (root!=NULL)
			traversal(root, result);
		return result;
	}
	void traversal(TreeNode* root, vector<int> &result){
		if (root->left != NULL)
			traversal(root->left, result);
		if (root->right != NULL)
			traversal(root->right, result);
		result.push_back(root->val);
	}
};