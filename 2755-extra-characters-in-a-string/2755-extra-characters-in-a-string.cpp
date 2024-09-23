class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr}; // 26 lowercase letters
        bool isEndOfWord = false; // Marks the end of a word
    };

    // Insert word into the trie
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
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

        // Traverse DP array backwards
        for (int i = n - 1; i >= 0; --i) {
            // Assume character i is extra by default
            dp[i] = dp[i + 1] + 1;

            // Now use the trie to find matching dictionary words starting at i
            TrieNode* node = root;
            for (int j = i; j < n; ++j) {
                int idx = s[j] - 'a';
                if (!node->children[idx]) {
                    break; // No further match in the trie
                }
                node = node->children[idx];
                if (node->isEndOfWord) {
                    // If we find a valid word, update dp[i]
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        // Return the result which is dp[0]
        return dp[0];
    }
};
