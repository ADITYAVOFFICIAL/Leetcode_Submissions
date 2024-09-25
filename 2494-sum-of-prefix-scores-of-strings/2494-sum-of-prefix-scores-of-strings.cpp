class Solution {
public:
    // Trie Node structure
    struct TrieNode {
        TrieNode* children[26] = {};  // Pointers to child nodes
        int count = 0;  // How many words have passed through this node
    };
    
    // Insert a word into the Trie and update the count at each node
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
            node->count++;  // Increment count for the prefix
        }
    }
    
    // Calculate the prefix sum for a word
    int getPrefixSum(TrieNode* root, const string& word) {
        TrieNode* node = root;
        int sum = 0;
        for (char c : word) {
            int index = c - 'a';
            node = node->children[index];
            sum += node->count;  // Add the count for the current prefix
        }
        return sum;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();  // Create the root of the Trie
        
        // Insert all words into the Trie
        for (const string& word : words) {
            insert(root, word);
        }
        
        // Calculate prefix sum for each word
        vector<int> result;
        for (const string& word : words) {
            result.push_back(getPrefixSum(root, word));
        }
        
        return result;
    }
};
