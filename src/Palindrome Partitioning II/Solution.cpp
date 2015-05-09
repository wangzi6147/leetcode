class Solution {
public:
	int minCut(string s) {
		int len = s.length();
		int ** data = new int*[len];
		int * data_ = new int[len];
		//init
		for (int i = 0; i < len; i++){
			data[i] = new int[len];
			for (int j = 0; j < len; j++){
				data[i][j] = 0;
			}
			data_[i] = i + 1;
		}
		for (int i = 0; i < len-1; i++){
			data[i][i] = 1;
			data[i + 1][i] = 1;
		}
		data[len - 1][len - 1] = 1;

		//data 记录第i个字符到第j个字符组成的字符串是否为Palindrome
		for (int i = len - 2; i >= 0; i--){
			for (int j = i + 1; j < len; j++){
				if (s[i] == s[j] && data[i + 1][j - 1] == 1){
					data[i][j] = 1;
				}
			}
		}

		//data_ 记录最短分割次数
		for (int i = 1; i < len; i++){
			if (data[0][i] == 1){
				data_[i] = 1;
				continue;
			}
			for (int j = 0; j <= i; j++){
				if (data[j][i] == 1){
					data_[i] = min(data_[i], data_[j - 1] + 1);
				}
			}
		}

		int result = data_[len-1]-1;
		for (int i = 0; i < len; i++){
			delete[] data[i];
		}
		delete[] data;
		delete[] data_;
		return result;
	}
};