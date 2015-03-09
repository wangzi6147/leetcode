class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		posIndex.clear();
		pattern = p;
		source = s;
		sLen = strlen(s);
		if (pattern.size() != 0){
			//先查找不带*的字符，并记录
			for (int i = 0; i < pattern.size() - 1; i++){
				if (pattern[i + 1] != '*'&&pattern[i] != '*')
					posIndex.push_back(i);
			}
			if (pattern[pattern.size() - 1] != '*')
				posIndex.push_back(pattern.size() - 1);
			//把'*'删除
			for (int i = 0; i < pattern.size(); i++){
				if (pattern[i] == '*'){
					pattern.erase(i, 1);
					for (int j = 0; j < posIndex.size(); j++){
						if (i < posIndex[j]){
							posIndex[j] = posIndex[j] - 1;
						}
					}
				}
			}
		}
		else
		{
			return source.size() == 0;
		}
		if (source.size() == 0){
			if (pattern.size() == 0 || posIndex.size() == 0)
				return true;
			else
			{
				return false;
			}
		}
		//开始回溯
		return searchSol(0, 0, 0);
	}

private:
	int sLen;
	string source;
	string pattern;
	vector<int> posIndex;
	bool searchSol(int posInS, int posInP, int iIndex)
	{
		if (posInP == pattern.size() || posInS == sLen)
			return false;
		if (iIndex < posIndex.size() && (source[posInS] == pattern[posIndex[iIndex]] || pattern[posIndex[iIndex]] == '.')){
			if (posInS == sLen - 1 && (posIndex.size() == 0 || posIndex[iIndex] == (pattern.size() - 1) || posInP >= posIndex[posIndex.size() - 1]))
				return true;
			if (searchSol(posInS + 1, posIndex[iIndex] + 1, iIndex + 1))
				return true;
			else
			{
				if (posInP < posIndex[iIndex]){
					if (source[posInS] == pattern[posInP] || pattern[posInP] == '.'){
						if (posInS == sLen - 1 && (posIndex.size() == 0 || posInP >= posIndex[posIndex.size() - 1]))
							return true;
						if (searchSol(posInS + 1, posInP, iIndex))
							return true;
						else
						{
							if (searchSol(posInS, posInP + 1, iIndex))
								return true;
						}
					}
					else
					{
						if (searchSol(posInS, posInP + 1, iIndex))
							return true;
					}
				}
			}
		}
		else
		{
			int tempPos;
			if (posIndex.size() !=0)
				tempPos = posIndex[(iIndex == posIndex.size()) ? iIndex - 1 : iIndex];
			if (posIndex.size() == 0 || posInP < tempPos||(posInP>tempPos&&posInP<pattern.size())){
				if (source[posInS] == pattern[posInP] || pattern[posInP] == '.'){
					if (posInS == sLen - 1 && (posIndex.size() == 0 || posInP >= posIndex[posIndex.size() - 1]))
						return true;
					if (searchSol(posInS + 1, posInP, iIndex))
						return true;
					else
					{
						if (searchSol(posInS, posInP + 1, iIndex))
							return true;
					}
				}
				else
				{
					if (searchSol(posInS, posInP + 1, iIndex))
						return true;
				}
			}
		}
		return false;
	}
};