//Copy From ChatGPT//
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // Ensure nums1 is the smaller array
        if (m > n) {
            swap(nums1, nums2);
            swap(m, n);
        }

        int left = 0, right = m, halfLen = (m + n + 1) / 2;

        while (left < right) {
            int i = left + (right - left) / 2;
            int j = halfLen - i;

            if (nums1[i] < nums2[j - 1])
                left = i + 1;
            else
                right = i;
        }

        int i = left, j = halfLen - left;

        int maxOfLeft = max(i > 0 ? nums1[i - 1] : INT_MIN, j > 0 ? nums2[j - 1] : INT_MIN);

        if ((m + n) % 2 == 1)
            return maxOfLeft;

        int minOfRight = min(i < m ? nums1[i] : INT_MAX, j < n ? nums2[j] : INT_MAX);

        return (maxOfLeft + minOfRight) / 2.0;
    }
};
