class Solution {
public:
    int climbStairs(int n) {
        vector<int> num(n+1);
        num[0] = 1;
        num[1] = 1;
        for(int i = 2; i <= n  ;i++)
        {
            num[i] = num[i-1] + num[i-2];
        }
        return num[n];
    }
};