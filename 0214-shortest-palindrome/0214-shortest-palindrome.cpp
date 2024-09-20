class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        
        // Reverse the input string
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Combine original string and reversed string with a separator
        string combined = s + "#" + rev_s;
        
        // KMP partial match table for the combined string
        vector<int> kmp_table(combined.size(), 0);
        
        // Build the KMP table (longest prefix that is also a suffix)
        for (int i = 1; i < combined.size(); ++i) {
            int j = kmp_table[i - 1];
            
            while (j > 0 && combined[i] != combined[j]) {
                j = kmp_table[j - 1];
            }
            
            if (combined[i] == combined[j]) {
                ++j;
            }
            
            kmp_table[i] = j;
        }
        
        // Length of the longest palindromic prefix
        int longest_palindrome_length = kmp_table.back();
        
        // Append the non-palindromic suffix from the reversed string to the front of the original string
        return rev_s.substr(0, n - longest_palindrome_length) + s;
    }
};
