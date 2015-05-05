class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int s1Size = 0, s2Size = 0, s3Size = 0;
		s1Size = s1.length();
		s2Size = s2.length();
		s3Size = s3.length();
		if (s1Size + s2Size != s3Size)
			return false;
		int **data = new int*[s1Size+1];
		for (int i = 0; i < s1Size + 1; i++){
			data[i] = new int[s2Size + 1];
		}

		data[0][0] = 1;
		int pos = s2Size;
		for (int i = 0; i < s2Size; i++){
			if (s2[i] == s3[i])
				data[0][i + 1] = 1;
			else{
				pos = i;
				break;
			}
		}
		if (pos < s2Size){
			for (int i = pos + 1; i < s2Size + 1; i++){
				data[0][i] = 0;
			}
		}
		pos = s1Size;
		for (int i = 0; i < s1Size; i++){
			if (s1[i] == s3[i])
				data[i + 1][0] = 1;
			else{
				pos = i;
				break;
			}
		}
		if (pos < s1Size){
			for (int i = pos + 1; i < s1Size + 1; i++){
				data[i][0] = 0;
			}
		}

		for (int i = 1; i < s1Size + 1; i++){
			for (int j = 1; j < s2Size + 1; j++){
				data[i][j] = (data[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (data[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
			}
		}

		int result = data[s1Size][s2Size];

		for (int i = 0; i < s1Size + 1; i++){
			delete[] data[i];
		}
		delete[] data;

		return result;
	}
};