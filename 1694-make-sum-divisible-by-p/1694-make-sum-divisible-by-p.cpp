class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        //Calculate the total sum of the array
        long total_sum = accumulate(nums.begin(), nums.end(), 0L);  // long to avoid overflow
        int target = total_sum % p;
        
        // If the total sum is already divisible by p
        if (target == 0) return 0;

        //Use a hashmap to track the prefix sums mod p
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;  // to handle cases where the subarray starts from the beginning
        int min_length = nums.size();
        long prefix_sum = 0;

        //Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            int mod = prefix_sum % p;

            //Check if we have seen a prefix sum that can make the remaining sum divisible by p
            int desired = (mod - target + p) % p;  // ensure non-negative
            if (prefix_map.find(desired) != prefix_map.end()) {
                min_length = min(min_length, i - prefix_map[desired]);
            }

            //Store the current prefix sum mod p
            prefix_map[mod] = i;
        }

        //If we found a valid subarray, return its length, otherwise return -1
        return min_length == nums.size() ? -1 : min_length;
    }
};