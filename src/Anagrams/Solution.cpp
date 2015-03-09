class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		std::map<string, int> map;
		std::map<string, string> record;
		vector<string> result;
		for (string str : strs){
			string temp = str;
			if (temp != "")
				sort(temp, 0, temp.length() - 1);
			if (map.find(temp) != map.end()){
				if (map[temp] == 1)
					result.push_back(record[temp]);
				result.push_back(str);
				map[temp]++;
			}
			else{
				record.insert(pair<string, string>(temp, str));
				map.insert(pair<string, int>(temp, 1));
			}
		}
		return result;
	}
	void sort(string &str, int low, int high){
		if (low >= high)
			return;
		char key = str[low];
		int first = low, last = high;
		while (first < last){
			while (first<last&&str[last] >= key)
				last--;
			str[first] = str[last];
			while (first<last&&str[first] <= key)
				first++;
			str[last] = str[first];
		}
		str[first] = key;
		sort(str, low, first - 1);
		sort(str, first + 1, high);
	}
};