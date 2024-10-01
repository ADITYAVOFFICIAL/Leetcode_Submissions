class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);
        
        // Calculate remainder counts
        for (int num : arr) {
            int rem = ((num % k) + k) % k;  // Handle negative remainders
            remainderCount[rem]++;
        }
        
        // Check for each remainder
        for (int r = 1; r < k; ++r) {
            if (remainderCount[r] != remainderCount[k - r]) {
                return false;  // If we can't pair r with k - r
            }
        }
        
        // Special case for remainder 0
        if (remainderCount[0] % 2 != 0) {
            return false;  // If there are odd numbers of remainder 0, can't pair them
        }
        
        return true;
    }
};
