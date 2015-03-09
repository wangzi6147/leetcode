class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		map<int, int> res;
		int maxResult = 0;
		for (int i = 0; i < num.size(); i++){
			if (res.find(num[i])==res.end())
				res.insert(pair<int, int>(num[i], 1));
		}
		int count = 0;
	    map<int, int>::iterator it;
		for (it = res.begin(); it != res.end();){
			int tmp = it->first;
			count = it->second;
			res.erase(it++);
			while (res.find(tmp + 1) != res.end()){
				tmp++;
				count++;
				if (it->first == tmp)
					it++;
				res.erase(tmp);
			}
			while (res.find(tmp-1)!= res.end())
			{
				tmp--;
				count++;
				if (it->first == tmp)
					it++;
				res.erase(tmp);
			}
			maxResult = maxResult > count ? maxResult: count;
			count = 0;
		}
		return maxResult;
	}
};