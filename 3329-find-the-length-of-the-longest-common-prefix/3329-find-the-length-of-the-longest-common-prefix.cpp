

class TrieNode {
public:
    TrieNode* children[10];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a number as a string into the Trie
    void insert(const std::string& num) {
        TrieNode* node = root;
        for (char ch : num) {
            int idx = ch - '0';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    // Find the length of the longest common prefix between a number and any number in the Trie
    int longestCommonPrefix(const std::string& num) {
        TrieNode* node = root;
        int len = 0;
        for (char ch : num) {
            int idx = ch - '0';
            if (!node->children[idx]) break;  // No further match
            node = node->children[idx];
            len++;
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        Trie trie;
        
        // Insert all numbers from arr1 into the Trie as strings
        for (int num : arr1) {
            trie.insert(std::to_string(num));
        }
        
        int maxLength = 0;
        
        // Find the longest common prefix between arr2 numbers and Trie
        for (int num : arr2) {
            int commonLen = trie.longestCommonPrefix(std::to_string(num));
            maxLength = std::max(maxLength, commonLen);
        }
        
        return maxLength;
    }
};
