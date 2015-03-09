class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		map<char, char> m;
		m.insert(pair<char, char>('(', ')'));
		m.insert(pair<char, char>('[', ']'));
		m.insert(pair<char, char>('{', '}'));
		for (int i = 0; i < s.length(); i++){
			char c = s[i];
			if (c == '(' || c == '[' || c == '{'){
				st.push(c);
			}
			else
			{
				if (st.empty()||c != m[st.top()])
					return false;
				else
				{
					st.pop();
				}
			}
		}
		return st.empty();
	}
};