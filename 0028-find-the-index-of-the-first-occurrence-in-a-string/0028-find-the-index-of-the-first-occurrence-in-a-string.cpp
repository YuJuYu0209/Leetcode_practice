class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i <= haystack.size() - needle.size() && haystack.size() >= needle.size(); i++)
        {
            if(haystack[i] == needle[0])
            {
                for(int j = 0; j < needle.size(); j++)
                {
                    if(haystack[i+j] != needle[j])
                    {
                        break;
                    }
                    else if(j == needle.size()-1)
                    {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};