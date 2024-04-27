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
        int last = binary.size()-1;
        for(int i = 0; i < binary.size() ; i++)
        {
            cout<<binary[i];
            if(binary[i]==1)
            {
                if(max <  i -last)
                {
                    max =  i - last;
                }
                last = i;
            }
        }
        return max;
    }
};