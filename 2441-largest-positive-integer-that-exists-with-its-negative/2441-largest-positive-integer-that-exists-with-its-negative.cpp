class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[i] == -nums[j] && nums[i] > ans)
                {
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
};