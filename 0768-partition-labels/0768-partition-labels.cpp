class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> charMap;
        vector<int> parts;
        for(int i = 0 ; i < s.size();++i){
            char c = s[i];
            charMap[c] = i;
        }
        int size = 0 , end = 0;
        for(int i = 0 ; i < s.size();++i){
            char c = s[i];
            if(charMap[c] > end)
                end = charMap[c];
            size++;
            if(i == end ){
                parts.push_back(size);
                size=0;end=0;
            }
        }
        return parts;
    }
};