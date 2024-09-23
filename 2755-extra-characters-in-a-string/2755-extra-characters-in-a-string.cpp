class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        // Create a set for fast lookup of dictionary words
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        // DP array where dp[i] is the minimum extra characters starting from index i
        vector<int> dp(n + 1, 0);
        
        // Fill the dp array from right to left
        for (int i = n - 1; i >= 0; --i) {
            // By default, consider the current character as extra
            dp[i] = dp[i + 1] + 1;
            
            // Try to match any word in the dictionary starting from index i
            for (int len = 1; len <= n - i; ++len) {
                string word = s.substr(i, len);
                if (dict.count(word)) {
                    dp[i] = min(dp[i], dp[i + len]);
                }
            }
        }
        
        // The answer is dp[0], which represents the minimum extra characters starting from index 0
        return dp[0];
    }
};
