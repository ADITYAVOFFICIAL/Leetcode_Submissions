class Solution {
public:
    int findKthNumber(int n, int k) {
        // Function to count the numbers between prefix and next prefix
        auto countSteps = [&](long prefix, long n) -> int {
            long steps = 0;
            long cur = prefix, next = prefix + 1;
            while (cur <= n) {
                steps += min(n + 1, next) - cur;
                cur *= 10;
                next *= 10;
            }
            return steps;
        };
        
        long current = 1;
        k--;  // Because we consider the 1st number (1) as already taken.
        
        while (k > 0) {
            int steps = countSteps(current, n);
            if (steps <= k) {
                // Move to next sibling in the tree (current + 1)
                k -= steps;
                current++;
            } else {
                // Move down the tree (current * 10)
                current *= 10;
                k--;
            }
        }
        
        return current;
    }
};
