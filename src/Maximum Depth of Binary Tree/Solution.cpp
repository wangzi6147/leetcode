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
	int depth = 1, max = 1;
	int maxDepth(TreeNode *root) {
		if(root == NULL)
		    return 0;
		if (root->left != NULL){
			depth++;
			max = max > depth ? max : depth;
			maxDepth(root->left);
		}
		if (root->right != NULL){
			depth++;
			max = max > depth ? max : depth;
			maxDepth(root->right);
		}
		depth--;
		return max;
	}
};