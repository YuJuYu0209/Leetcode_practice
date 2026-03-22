bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) 
{
    int n = matSize;

    for (int k = 0; k < 4; k++) // 檢查0度、90度、180度、270度
    {
        bool match = true;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] != target[i][j])
                {
                    match = false;
                    break;
                }
            }
        }

        if(match) return true;

        // 對角線反轉
        for(int i = 0; i < n; i++)
        {
           for(int j = i; j < n; j++)
           {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
           } 
        }

        // 左右反轉
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n / 2; j++)
            {
                int temp = mat[i][j];
                mat[i][j] = mat[i][n - 1 - j];
                mat[i][n - 1 - j] = temp;
            }
        }
    }    
    return false;
}

