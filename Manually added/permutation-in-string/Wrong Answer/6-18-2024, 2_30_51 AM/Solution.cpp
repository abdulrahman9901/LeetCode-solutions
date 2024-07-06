// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0,r=0;
        map<char,bool>found;
        while(r < s2.length()){
            auto pos = s1.find_first_of(s2[r]);
           if( pos == string::npos){
                r++;
                l=r;
            }else{
                cout<<"s1[pos] , pos : "<<s1[pos]<<" , "<<pos<<endl;
                if(found[s1[pos]])
                    l++;
                else 
                    found[s1[pos]] = true;
                if(r-l+1 == s1.length()){
                    cout<<r<<" : "<<l<<endl;
                    return true;
                }
                // s1[pos] = '\0';
                r++;
            }

        }
        return false;
    }
};