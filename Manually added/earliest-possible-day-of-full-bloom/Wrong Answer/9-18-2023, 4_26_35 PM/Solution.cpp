// https://leetcode.com/problems/earliest-possible-day-of-full-bloom

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        size_t i = 0, j = 0, total = 0, len = growTime.size();
        if(len == 1 )
            return growTime[0] +plantTime[0] ;
        while (j <= len - 1 && growTime[len-1]) {
            if (plantTime[i] != 0)
                plantTime[i] -= 1;

            if (growTime[j] != 0) {
                if (i > j || (i == j && plantTime[len-1]==0) )
                    {growTime[j] -= 1;}
            } else {
                j++;
                 if (i > j || (i == j && plantTime[len-1]==0) )
                    {growTime[j] -= 1;}
            }

            if (plantTime[i] == 0 && i < len - 1)
                i++;
            total++;
            cout<<total<<" "<<i<<" "<<j<<" "<<plantTime[i]<<" "<<growTime[j]<<endl;
        }

        return total;
    }
};
