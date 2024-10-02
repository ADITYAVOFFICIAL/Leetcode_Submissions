class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;  // Create a copy of the original array
        sort(sortedArr.begin(), sortedArr.end());  // Sort the copy
        
        unordered_map<int, int> rankMap;  // Map to store the rank for each element
        int rank = 1;
        
        // Assign ranks based on the sorted array
        for (int num : sortedArr) {
            // If the element is not already ranked, assign it the current rank
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }
        
        // Replace each element in the original array with its rank
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rankMap[arr[i]];
        }
        
        return arr;
    }
};
