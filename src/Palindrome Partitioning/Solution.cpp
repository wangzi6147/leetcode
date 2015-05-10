class Solution {
public:
    int len = 0;
    int ** data = NULL;
    vector<vector<string>> partition(string s) {
        len = s.length();
		data = new int*[len];
		vector<vector<string>> result = {{}};
		
		//init
		for (int i = 0; i < len; i++){
			data[i] = new int[len];
			for (int j = 0; j < len; j++){
				data[i][j] = 0;
			}
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
		
		push(0, result, s);
		result.pop_back();
		return result;
    }
    
    //result
    void push(int i, vector<vector<string>> &result, string s){
        for(int j = i;j<len;j++){
            if(data[i][j] == 1){
                result.back().push_back(s.substr(i, j-i+1));
                if(j==len-1){
                    vector<string> temp = result.back();
                    result.insert(result.begin(), temp);
                }
                push(j+1, result, s);
                result.back().pop_back();
            }
        }
        return;
    }
};