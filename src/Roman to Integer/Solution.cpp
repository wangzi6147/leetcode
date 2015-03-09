class Solution {
public:
	int romanToInt(string s) {
		int len = s.size();
		int total = 0;
		int * pInt = new int[len];
		for (int i = 0; i < len; i++){
			*(pInt + i) = charToInt(s[i]);
		}
		for (int i = 0; i < len - 1; i++){
			if (*(pInt + i) < *(pInt + i + 1)){
				total = total - *(pInt + i);
			}
			else
			{
				total = total + *(pInt + i);
			}
		}

		total = total + *(pInt + len - 1);

		delete[] pInt;

		return total;
	}

private:
	int charToInt(char c){
		switch (c)
		{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default:return 0;
			break;
		}
	}
};