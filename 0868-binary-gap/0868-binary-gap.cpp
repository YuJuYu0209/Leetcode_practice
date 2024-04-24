class Solution {
public:
    int binaryGap(int n) {
        
        vector<int> binary;
        while(n>0)
        {
            binary.push_back(n % 2);
            n = n / 2;
        }
        int max = 0;
        int last = 0;
        for(int i = binary.size() - 1; i >= 0 ; i--)
        {
            if(binary[i]==1)
            {
                if(max < (last - i))
                {
                    max = last - i;
                }
                last = i;
            }
        }
        return max;
    }
};