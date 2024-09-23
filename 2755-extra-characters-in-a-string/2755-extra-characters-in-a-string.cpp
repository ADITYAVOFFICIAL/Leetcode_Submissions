class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr}; // Only 26 lowercase letters
        bool isEndOfWord = false; // Mark the end of a valid word
    };
    
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEndOfWord = true;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        
        // Build the trie from the dictionary
        TrieNode* root = new TrieNode();
        for (const string& word : dictionary) {
            insert(root, word);
        }
        
        // DP array to store the minimum extra characters from index i onwards
        vector<int> dp(n + 1, 0);
        
        // Fill dp array from right to left
        for (int i = n - 1; i >= 0; --i) {
            // By default, consider the current character as extra
            dp[i] = dp[i + 1] + 1;
            
            // Now use the trie to find matching dictionary words starting at i
            TrieNode* node = root;
            for (int j = i; j < n; ++j) {
                if (!node->children[s[j] - 'a']) {
                    break; // No matching prefix
                }
                node = node->children[s[j] - 'a'];
                if (node->isEndOfWord) {
                    // If we find a word, minimize the extra characters
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }
        
        return dp[0];
    }
};
