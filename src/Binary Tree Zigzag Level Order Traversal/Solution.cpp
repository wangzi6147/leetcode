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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> vectorForTree;
		while (!isBottom){
			vectorForLayer.clear();
			getLayerVector(root);
			if (vectorForLayer.size()!=0)
				vectorForTree.push_back(vectorForLayer);
			isLeft = !isLeft;
			targetLayerNum++;
		}
		return vectorForTree;
	}


private:
	bool isBottom = false;
	bool isLeft = true;
	int targetLayerNum = 0;
	int curLayerNum;
	vector<int> vectorForLayer;
	void getLayerVector(TreeNode * root)
	{
		curLayerNum = 0;
		getValue(root);
		if (vectorForLayer.size() == 0)
			isBottom = true;
	}

	void getValue(TreeNode * node)
	{
		if (node == NULL)
			return;
		if (curLayerNum > targetLayerNum)
			return;
		if (curLayerNum == targetLayerNum)
			vectorForLayer.push_back(node->val);
		curLayerNum++;
		if (isLeft){
			getValue(node->left);
			getValue(node->right);
			curLayerNum--;
			return;
		}
		else
		{
			getValue(node->right);
			getValue(node->left);
			curLayerNum--;
			return;
		}
	}


};