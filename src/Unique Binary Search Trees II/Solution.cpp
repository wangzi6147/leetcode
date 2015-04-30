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
	vector<TreeNode *> generateTrees(int n) {
		vector<vector<TreeNode *>> data;

		vector<TreeNode*> temp0;
		TreeNode * p0 = NULL;
		temp0.push_back(p0);
		data.push_back(temp0);

		vector<TreeNode*> temp1;
		TreeNode * p1 = NULL;
		p1 = new TreeNode(1);
		temp1.push_back(p1);
		data.push_back(temp1);

		for (int i = 2; i <= n; i++)
		{
			vector<TreeNode * > resultTemp;
			for (int j = i; j > 0; j--){
				vector<TreeNode*> leftTemp;
				vector<TreeNode*> rightTemp;
				for (int k = 0; k < data[j - 1].size();k++)
				{
					TreeNode* oneBranch = NULL;
					TreeNode* head = NULL;
					oneBranch = clone(data[j - 1][k], 0);
					head = new TreeNode(j);
					head->left = oneBranch;
					leftTemp.push_back(head);
				}
				for (int k = 0; k < data[i-j].size(); k++)
				{
					TreeNode* oneBranch = NULL;
					oneBranch = clone(data[i - j][k], j);
					for (int l = 0; l < leftTemp.size(); l++){
						TreeNode * finalHead = NULL;
						finalHead = clone(leftTemp[l], 0);
						finalHead->right = oneBranch;
						rightTemp.push_back(finalHead);
					}
				}
				for (int k = 0; k < rightTemp.size(); k++){
					resultTemp.push_back(rightTemp[k]);
				}
			}
			data.push_back(resultTemp);
		}

		return data[n];
	}

	TreeNode* clone(TreeNode * node, int up)
	{
		TreeNode * head = NULL;
		TreeNode * left = NULL;
		TreeNode * right = NULL;
		if (node != NULL){
			head = new TreeNode(node->val+up);
			if (node->left != NULL){
				left = clone(node->left, up);
				head->left = left;
			}
			if (node->right != NULL){
				right = clone(node->right, up);
				head->right = right;
			}
		}
		return head;
	}
};