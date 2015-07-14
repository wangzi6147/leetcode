
//注意：字符串insert或者erase之后迭代器会失效，需要重置，或者利用函数直接返回的迭代器

class Solution {
public:
    void reverseWords(string &s) {
        
        if (s.length() == 0)
			return;
			
		//delete all leading or trailing spaces
		string::iterator it;
		it = s.begin();
		while (it != s.end() && *it == ' '){
			it = s.erase(it);
		}
		if (it == s.end())
			return;
		it = s.end()-1;
		while (*it == ' '){
			it = s.erase(it);
			it--;
		}
		
		//reversing
		string::iterator beginIt;
		s.insert(0, 1, ' ');
		s.insert(s.end(), ' ');
		beginIt = s.begin();
		it = s.end() - 1;
		while (it != beginIt){
			if (*(it - 1) == ' '){
			    //make sure only single space between words
				if (*it == ' '){
					it = s.erase(it);
					it--;
					continue;
				}
				
				queue<char> temp;
				
				while (it != s.end()){
				    temp.push(*it);
					it = s.erase(it);
				}
				if(!temp.empty()){
				    while(!temp.empty()){
					    beginIt = s.insert(beginIt, temp.front());
					    beginIt++;
					    temp.pop();
				    }
				    it = s.end();
				}
			}
			it--;
		}
		s.erase(s.end() - 1);
		s.erase(s.end() - 1);
		return;
    }
};