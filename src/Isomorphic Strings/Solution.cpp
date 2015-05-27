class Solution {
public:
	bool isIsomorphic(string s, string t) {
		char cs, ct;
		map<char, char> m;
		map<char, int> m2;
		for (int i = 0; i < s.length(); i++){
			cs = s[i];
			ct = t[i];
			if (m.find(cs) == m.end()){
			    if(m2.find(ct)==m2.end()){
				    m.insert(pair<char, char>(cs, ct));
				    m2.insert(pair<char,char>(ct,1));
			    }
			}
			if (m[cs] != ct){
				return false;
			}
		}
		return true;
	}
};