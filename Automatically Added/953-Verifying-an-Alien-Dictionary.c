bool isAlienSorted(char** words, int wordsSize, char* order) {
    int map[26];
    for(int i = 0; order[i] != '\0'; i++)
        map[order[i]-'a'] = i;
    
    for(int i = 1 ; i < wordsSize ; ++i){
        for(int j = 0 ; words[i-1][j] != '\0';++j){
            char c1 = words[i-1][j];
            char c2 = words[i][j];
            if(c2 =='\0') return false;
            if(c1 != c2){
                if(map[c1 -'a'] > map[c2 -'a']) return false;
                else break;
            }
        }
    }
    return true;
}   