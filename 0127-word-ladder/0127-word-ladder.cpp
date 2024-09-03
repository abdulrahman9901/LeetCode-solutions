class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> seqMap;
        map<string,bool> visited;
        queue<string> processQ;
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end())
            return 0;
        if(find(wordList.begin(),wordList.end(),beginWord) == wordList.end())
            wordList.push_back(beginWord);

        for(auto word:wordList){
            for(int j = 0 ; j < word.size();++j){
                string pattern = word;
                pattern[j] = '*';
                seqMap[pattern].push_back(word);
            }
        }
        int res = 1;
        processQ.push(beginWord);
        visited[beginWord] = true;
       
        while(!processQ.empty()){
            int levelSize = processQ.size();  

            for (int i = 0; i < levelSize; ++i) {
                string word = processQ.front();
                processQ.pop();
                cout<<word<<endl;
                for(int j = 0 ; j < word.size();++j){
                    string pattern = word;
                    pattern[j] = '*';
                    for(string wordPattern : seqMap[pattern]){
                        if(wordPattern == endWord)
                            return res+1;
                        if(!visited[wordPattern]){
                            processQ.push(wordPattern);
                            visited[wordPattern] = true;
                            }
                        }
                    }
                }
            res++;        
        }
        return 0;
    }
};