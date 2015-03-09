class Solution {
public:
	string intToRoman(int num) {
		string result;
		for (int i = 0; i < 4; i++){
			result = result + parse((int)(num/pow(10,(3-i))),i);
			num = num % (int)(pow(10, (3 - i)));
		}
		return result;
	}

	string parse(int num, int type)
	{
		if (num == 0)
			return "";
		char bigNum, middleNum, smallNum;
		string result;
		switch (type)
		{
		case 0:
			smallNum = 'M';
			break;
		case 1:
			bigNum = 'M';
			middleNum = 'D';
			smallNum = 'C';
			break;
		case 2:
			bigNum = 'C';
			middleNum = 'L';
			smallNum = 'X';
			break;
		case 3:
			bigNum = 'X';
			middleNum = 'V';
			smallNum = 'I';
			break;
		default:
			break;
		}
		if (num < 4)
			for (int i = 0; i < num; i++){
				result = result + smallNum;
			}
		else if (num == 4)
		{
			result = result + smallNum + middleNum;
		}else if (num<9)
		{
			result = result + middleNum;
			for (int i = 0; i < num - 5;i++)
			{
				result = result + smallNum;
			}
		}
		else
		{
			result = result + smallNum + bigNum;
		}
		return result;
	}
};