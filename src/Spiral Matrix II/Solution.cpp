class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
	    vector<vector<int>> result;
	    if(n==0)
	        return result;
		int i = (n % 2) * 2;
		int count = n*n - 1;
		result = { { n*n } };
		vector<int> temp;
		while (count > 0){
			switch (i % 4){
				//向上
			case 0:
				for (int j = result.size() - 1; j >= 0; j--){
					result[j].push_back(count);
					count--;
				}
				break;
				//向左
			case 1:
				temp.clear();
				for (int j = result[0].size() - 1; j >= 0; j--){
					temp.insert(temp.begin(), count);
					count--;
				}
				result.insert(result.begin(), temp);
				break;
				//向下
			case 2:
				for (int j = 0; j<result.size(); j++){
					result[j].insert(result[j].begin(), count);
					count--;
				}
				break;
				//向右
			case 3:
				temp.clear();
				for (int j = 0; j < result[0].size(); j++){
					temp.push_back(count);
					count--;
				}
				result.push_back(temp);
				break;
			defalt:
				break;
			}
			i++;
		}
		return result;
	}
};