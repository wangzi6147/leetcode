class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        map<char, int> ms, mt;
        map<char, int>::iterator it;
        for(int i = 0;i<s.length();i++){
            if(ms.find(s[i])==ms.end()){
                ms.insert(pair<char, int>(s[i], 1));
            }else{
                ms[s[i]]++;
            }
            if(mt.find(t[i])==mt.end()){
                mt.insert(pair<char, int>(t[i], 1));
            }else{
                mt[t[i]]++;
            }
        }
        for(it=ms.begin();it!=ms.end();it++){
            if(mt.find(it->first)==mt.end()){
                return false;
            }else if(it->second!=mt[it->first]){
                return false;
            }
        }
        return true;
    }
};