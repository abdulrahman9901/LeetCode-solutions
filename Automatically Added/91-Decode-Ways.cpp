class Solution {
    void dfs(vector<int> &dp,string s,int i){
        if(dp[i] != -1)
            return;
            
        if(s[i] == '0'){
            dp[i] = 0;
            return;
        }
        dp[i] = 0;

        if(i+1 <= s.size()){
            dfs(dp,s,i+1);
            dp[i] += dp[i+1];
        }

        if(i+2 <= s.size() && (s[i]== '1' || (s[i] == '2' && s[i+1] <= '6' ))){
            dfs(dp,s,i+2);
            dp[i]+=dp[i+2];
        }
        cout<<i<<" "<<dp[i]<<endl;
    }
public:
    int numDecodings(string s) {

        if (s.empty()) return 1;   
        if (s[0] == '0') return 0; 
        vector<int> dp(s.size()+1,-1);

        dp[s.size()] = 1; 

        dfs(dp,s,0);

        return dp[0];
    }
};