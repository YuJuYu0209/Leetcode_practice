class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // 判斷字串是否以元音開頭和結尾的輔助函數
        auto isVowelString = [](const string& word) -> bool 
        {
            unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
            return vowels.count(word.front()) && vowels.count(word.back());
        };
        
        int n = words.size();
        vector<int> prefixSum(n + 1, 0);

        // 建立前綴和陣列
        for (int i = 0; i < n; ++i) 
        {
            prefixSum[i + 1] = prefixSum[i] + (isVowelString(words[i]) ? 1 : 0);
        }

        vector<int> results;

        // 處理查詢
        for (const auto& query : queries) 
        {
            int li = query[0];
            int ri = query[1];
            results.push_back(prefixSum[ri + 1] - prefixSum[li]);
        }

        return results;
    }
};