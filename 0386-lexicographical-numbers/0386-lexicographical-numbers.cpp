class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1; // Start with the smallest number
        
        for (int i = 0; i < n; i++) {
            result.push_back(curr); // Add the current number to the result
            
            // Calculate the next number in lexicographical order
            if (curr * 10 <= n) {
                curr *= 10; // Go to the next level
            } else {
                if (curr >= n) {
                    curr /= 10; // If curr exceeds n, go up one level
                }
                curr++; // Move to the next number
                while (curr % 10 == 0) {
                    curr /= 10; // Remove trailing zeros
                }
            }
        }
        
        return result;
    }
};
