class Solution {
public:
	bool isPalindrome(int x) {
	    if(x<0)
	        return false;
		int len;
		for (int i = 1; i < 20; i++){
			if ((int)(x / pow(10,i)) == 0){
				len = i;
				break;
			}
		}
		if (len == 1)
			return true;
		if (x % 10 != (int)(x / pow(10, len-1)))
			return false;
		int backNum, frontNum;
		for (int i = 2; i <= len / 2; i++){
			backNum = (int)((x%(int)pow(10, i))/pow(10,i-1));
			frontNum = (int)(x / pow(10, len - i))%10;
			if (backNum != frontNum)
				return false;
		}
		return true;
	}
};