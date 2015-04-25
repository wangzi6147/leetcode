class Solution {
public:
	bool ifDone = false;
	vector<int> candidates;
	vector<vector<int>> result;
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		//ÅÅÐò
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		vector<int> temp;
		result.push_back(temp);
		//»ØËÝ·¨
		backTrack(0, target);
		if (result.back().size() == 0)
			result.pop_back();
		return result;
	}

	void backTrack(int index, int target)
	{
		if (index == candidates.size())
			return;
		int value = candidates[index];
		result.back().push_back(value);
		if (value < target){
			backTrack(index, target - value);
		}
		else if (value > target){
			result.back().pop_back();
			return;
		}
		else {
			ifDone = true;
			return;
		}
		if (ifDone){
			vector<int> temp;
			temp = result.back();
			temp.pop_back();
			result.push_back(temp);
			ifDone = false;
		}
		result.back().pop_back();
		backTrack(index + 1, target);
		return;
	}
};