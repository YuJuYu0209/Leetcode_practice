class Solution(object):
    def maxProductPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        MOD = 10**9 + 7

        # 準備兩張初始化為0的地圖
        dp_max = [[0] * n for _ in range(m)]
        dp_min = [[0] * n for _ in range(m)]

        # 設定起點
        dp_max[0][0] = dp_min[0][0] = grid[0][0]

        # 遍歷地圖
        for i in range(m):
            for j in range(n):
                # 跳過起點
                if i == 0 and j == 0:
                    continue
                candidates = []

                # 如果上方有格子，就拿上方的「最大」和「最小」來乘目前的格子
                if i > 0:
                    candidates.append(dp_max[i-1][j] * grid[i][j])
                    candidates.append(dp_min[i-1][j] * grid[i][j])

                # 如果左方有格子，就拿左方的「最大」和「最小」來乘目前的格子
                if j > 0:
                    candidates.append(dp_max[i][j-1] * grid[i][j])
                    candidates.append(dp_min[i][j-1] * grid[i][j]) 

                # 錄這四個結果中，誰最大，誰最小
                dp_max[i][j] = max(candidates)
                dp_min[i][j] = min(candidates)
        
        res = dp_max[m-1][n-1]

        return res % MOD if res >= 0 else -1    