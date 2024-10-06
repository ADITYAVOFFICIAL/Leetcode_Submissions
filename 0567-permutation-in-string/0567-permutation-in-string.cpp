using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        
        if (n1 > n2) {
            return false;  // s1 is larger than s2, so no permutation can be a substring.
        }
        
        // Frequency count for s1 and the current window in s2
        vector<int> count1(26, 0), count2(26, 0);
        
        // Fill the frequency count for the first window of length n1
        for (int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        
        // Check if the first window matches
        if (count1 == count2) {
            return true;
        }
        
        // Slide the window across s2
        for (int i = n1; i < n2; i++) {
            // Add the new character (s2[i]) to the window
            count2[s2[i] - 'a']++;
            // Remove the old character (s2[i - n1]) from the window
            count2[s2[i - n1] - 'a']--;
            
            // Check if the frequency counts match
            if (count1 == count2) {
                return true;
            }
        }
        
        return false;  // No matching permutation found
    }
};