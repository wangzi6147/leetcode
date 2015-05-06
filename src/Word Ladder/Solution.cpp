class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		int size = beginWord.size();
		unordered_set<string>::iterator i;
		queue<vector<string>> q1, q2;
		q1.push(vector<string>({ beginWord }));
		q2.push(vector<string>({ endWord }));
		int count1 = 1,count2 = 1;
		while (!q1.front().empty() && !q2.front().empty()){
			for (string word1 : q1.front()){
				for (string word2 : q2.front()){
					if (isLadder(word1, word2, size))
						return count1 + count2;
				}
			}
			if (q1.front().size() < q2.front().size()){
				count1++;
				q1.push(vector<string>());
				for (string word : q1.front()){
					for (i = wordDict.begin(); i != wordDict.end();){
						if (isLadder(word, *i, size)){
							q1.back().push_back(*i);
							wordDict.erase(i++);
						}
						else
							i++;
					}
				}
				q1.pop();
			}
			else{
				count2++;
				q2.push(vector<string>());
				for (string word : q2.front()){
					for (i = wordDict.begin(); i != wordDict.end();){
						if (isLadder(word, *i, size)){
							q2.back().push_back(*i);
							wordDict.erase(i++);
						}
						else
							i++;
					}
				}
				q2.pop();
			}
		}
		return 0;
	}

	bool isLadder(string s1, string s2, int size)
	{
		int count = 0;
		for (int i = 0; i < size; i++){
			if (s1[i] != s2[i])
				count++;
			if (count>1)
				return false;
		}
		return count==1;
	}
};