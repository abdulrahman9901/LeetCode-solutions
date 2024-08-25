class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) 
            return true;

        int j = 0;
        while (j >= 0) {
            if (j >= nums.size() - 1) 
                return true;
            
            if (nums[j] > 0) {
                j += nums[j];
            } else {
                bool foundAlternative = false;
                
                for (int k = j - 1; k >= 0; --k) {
                    if (nums[k]+k > j ) {
                        j = k + nums[k];
                        foundAlternative = true;
                        break;
                    }
                }

                if (!foundAlternative) 
                    return false;
            }
        }

        return false;
    }
};
