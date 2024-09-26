#include<algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());//inserting the nums2 to nums1
        sort(nums1.begin(), nums1.end());//now sorting
        int n = nums1.size();//this will calculate the size
                if (n % 2 == 0) {//if divisible by 2 so we have two elements in the middle
            return (nums1[n/2 - 1] + nums1[n/2]) / 2.0;
        } else {//single median value
            return nums1[n/2];
        }
    }
};
