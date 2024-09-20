class Solution:
    def shortestPalindrome(self, s: str) -> str:
        # Reverse the string to check for overlaps with the prefix
        rev_s = s[::-1]
        # Combine the original string and reversed string with a special separator
        combined = s + "#" + rev_s
        
        # Compute the KMP table (partial match table)
        kmp_table = [0] * len(combined)
        
        for i in range(1, len(combined)):
            j = kmp_table[i - 1]
            while j > 0 and combined[i] != combined[j]:
                j = kmp_table[j - 1]
            if combined[i] == combined[j]:
                j += 1
            kmp_table[i] = j
        
        # The length of the palindrome is stored in the last position of the KMP table
        longest_palindrome_length = kmp_table[-1]
        
        # We need to add the reverse of the suffix (non-palindromic part) to the front
        suffix_to_add = rev_s[:len(s) - longest_palindrome_length]
        
        return suffix_to_add + s
