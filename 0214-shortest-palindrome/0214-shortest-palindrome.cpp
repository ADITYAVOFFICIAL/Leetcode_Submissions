class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Combine the original string, separator, and reversed string
        string combined = s + "#" + rev_s;
        int n = combined.size();
        
        // KMP partial match table
        vector<int> kmp_table(n, 0);
        
        // Build the KMP table
        for (int i = 1; i < n; ++i) {
            int j = kmp_table[i - 1];
            
            while (j > 0 && combined[i] != combined[j]) {
                j = kmp_table[j - 1];
            }
            if (combined[i] == combined[j]) {
                ++j;
            }
            kmp_table[i] = j;
        }
        
        // Find the length of the longest palindromic prefix
        int longest_palindrome_length = kmp_table[n - 1];
        
        // Add the necessary characters in front of the original string
        string suffix_to_add = rev_s.substr(0, s.size() - longest_palindrome_length);
        return suffix_to_add + s;
    }
};
