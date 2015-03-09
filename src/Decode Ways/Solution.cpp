class Solution {
public:
	int numDecodings(string s) {
		if (s == ""||s[0]=='0')
			return 0;
		int *p = new int[s.size()+1];
		p[0] = 1;
		p[1] = 1;
		for (int i = 2; i < s.size()+1; i++){
			int strInedex = i - 1;
			if (s[strInedex] == '0'){
				if (s[strInedex - 1] == '1' || s[strInedex - 1] == '2')
					p[i] = p[i - 2];
				else
					return 0;
			}
			else if ((s[strInedex] - '0') <= 6 && (s[strInedex - 1] == '1' || s[strInedex - 1] == '2') || (s[strInedex] - '0'>6) && s[strInedex - 1] == '1')
				p[i] = p[i - 2] + p[i - 1];
			else
				p[i] = p[i - 1];
		}
		int result = p[s.size()];
		delete[] p;
		return result;
	}
};