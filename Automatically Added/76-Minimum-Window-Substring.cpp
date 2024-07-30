class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> sMap ,tMap;
        int have = 0 , need = 0;
        int st = 0 , end = 0 , len = INT_MAX;
        int i , j = 0;


        if(s == t)
            return s;

        for(char c : t){
            tMap[c] += 1;
            sMap[c] = 0;
        }
        need = tMap.size();
        for( i = 0 ; i < s.length() ; ++i){
            if(tMap.find(s[i]) != tMap.end()){
                sMap[s[i]]++;
                if(sMap[s[i]] == tMap[s[i]]){
                    have++;
                }
                while(have == need){
                    if((i - j + 1) <= len){
                        st = j;
                        end = i;
                        len = i - j + 1;
                    }
                    if(tMap.find(s[j]) != tMap.end()){
                        sMap[s[j]]--;
                        if(sMap[s[j]] == tMap[s[j]] - 1){
                            have--;
                        }
                    }
                    j++;
                }
            }
        }
        return len == INT_MAX ? \\ : s.substr(st, len);
    }
};