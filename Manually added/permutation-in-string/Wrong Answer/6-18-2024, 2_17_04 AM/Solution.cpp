// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0,r=0;
        while(r < s2.length()){
            auto pos = s1.find(s2[r]);
           if( pos == string::npos){
                r++;
                l=r;
            }else{
                cout<<"s1[pos] : "<<s1[pos]<<endl;
                s1[pos] = '\0';
                if(r-l+1 == s1.length()){
                    cout<<r<<" : "<<l<<endl;
                    return true;
                }
                r++;
            }

        }
        return false;
    }
};