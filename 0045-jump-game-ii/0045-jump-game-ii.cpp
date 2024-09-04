class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, currentEnd = 0, farthest = 0;
        if(n<2) return 0;

        for(int i = 0;i < n-1; ++i ){
            farthest = max(farthest,nums[i]+i);
            
            if(currentEnd == i){
                currentEnd = farthest;
                jumps++;
            }

            if(currentEnd == n-1)
                break;
        }
        return jumps;
    }
};