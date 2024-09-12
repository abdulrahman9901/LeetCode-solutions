class Solution {
public:
    bool checkValidString(string s) {
        stack<int> opens;
        stack<int> stars;
        for(int i = 0 ; i < s.size() ; ++i){
            auto c = s[i];
            if(c == ')'){
                if(!opens.empty()){
                    opens.pop();
                }else if (!stars.empty()){
                    stars.pop();
                }else{
                    return false;
                }
            }else if (c == '*'){
                stars.push(i);
            }else {
                opens.push(i);
            }
        }
        while(!stars.empty() && !opens.empty()){
            if(stars.top() > opens.top()){
                opens.pop();
            }
            stars.pop();
        }
        return opens.empty();
    }
};