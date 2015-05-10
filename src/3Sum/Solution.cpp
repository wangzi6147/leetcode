class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size()<3)
			return result;
		sort(nums.begin(), nums.end());
		vector<int>::iterator i, ii;
		int lasti = nums[0]-1;
		int lastii;
		for (i = nums.begin(); i != nums.end(); i++){
			if (*i>0)
				break;
			if (lasti == *i)
				continue;
			lastii = nums[0] - 1;
			for (ii = i + 1; ii != nums.end(); ii++){
				if (lastii == *ii)
					continue;
				int temp = 0 - *i - *ii;
				if (temp < 0)
					break;
				if (binary_search(ii + 1, nums.end(), temp))
					result.push_back({ *i, *ii, temp });
				lastii = *ii;
			}
			lasti = *i;
		}
		return result;
	}
};