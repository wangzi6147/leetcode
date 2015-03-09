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
	int sumNumbers(TreeNode *root) {
		if (root == NULL){
			return 0;
		}
		vector<int> tmpVec;
		dFS(root, tmpVec);
		int result = 0;
		vector<vector<int>>::iterator it;
		for (it = vec.begin(); it != vec.end(); it++){
			int resultForEach = 0;
			for (int i = 0; i < it->size();i++){
				resultForEach = resultForEach + (*it)[i] * pow(10, ((it->size()) - 1 - i));
			}
			result = result + resultForEach;
		}
		return result;
	}


private:
	vector<vector<int>> vec;

	void dFS(TreeNode * root, vector<int> tmpVec)
	{
		tmpVec.push_back(root->val);
		if (root->left == NULL&&root->right == NULL){
			vec.push_back(tmpVec);
			return;
		}
		if (root->left != NULL&&root->right != NULL){
			dFS(root->left, tmpVec);
			vector<int> tmpVec_right;
			vector<int>::iterator it;
			for (it = tmpVec.begin(); it != tmpVec.end(); it++){
				tmpVec_right.push_back(*it);
			}
			dFS(root->right, tmpVec_right);
		}else if (root->left!=NULL)
		{
			dFS(root->left, tmpVec);
		}else if (root->right!=NULL)
		{
			dFS(root->right, tmpVec);
		}
	}
};
