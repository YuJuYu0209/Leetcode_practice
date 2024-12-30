class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        // 動態規劃表，最大長度為 high
        vector<int> dp(high + 1, 0);
        dp[0] = 1; // 初始條件：空字串只有一種構造方式
        int MOD = 1e9 + 7;
        // 填充 dp 表
        for (int i = 1; i <= high; ++i) 
        {
            if (i >= zero) 
            {
                dp[i] = (dp[i] + dp[i - zero]) % MOD; // 添加 '0' 的情況
            }
            if (i >= one) 
            {
                dp[i] = (dp[i] + dp[i - one]) % MOD; // 添加 '1' 的情況
            }
        }

        // 累加 [low, high] 範圍內的結果
        int result = 0;
        for (int i = low; i <= high; ++i) 
        {
            result = (result + dp[i]) % MOD;
        }

        return result;
    }
};