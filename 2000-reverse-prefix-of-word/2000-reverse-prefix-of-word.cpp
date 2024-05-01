class Solution {
public:
    string reversePrefix(string word, char ch) {
        // for(int i = 0; i < word.size();i++)
        // {
        //     if(word[i]==ch)
        //     {
        //         reverse(word.begin(),word.begin()+i+1);
        //         break;
        //     }
        // }
        auto i = find(word.begin(), word.end(), ch);
        if(i != word.end())
        {
            reverse(word.begin(), i+1);
        }
        return word;
    }
};