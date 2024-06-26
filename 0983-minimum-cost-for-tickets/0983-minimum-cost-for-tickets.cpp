class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366);
        int j = 0;
        for(int i = 1; i < 366; i++)
        {
            if(j < days.size() && i == days[j])
            {
                j++;
                dp[i] = min({dp[i-1]+costs[0], dp[max(0,i-7)]+costs[1], dp[max(0,i-30)]+costs[2]});
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        return dp[365];
    }
};