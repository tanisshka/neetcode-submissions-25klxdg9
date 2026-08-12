class Solution {
private:
    vector<int> MergeArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0;
        int j = 0;

        vector<int> merged;
        int k = 0;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i++]);
            }
            else {
                merged.push_back(nums2[j++]);
            }
        }

        while (i < n) {
            merged.push_back(nums1[i++]);
        }

        while (j < m) {
            merged.push_back(nums2[j++]);
        }

        return merged;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Brute force approach
        vector<int> merged = MergeArrays(nums1, nums2);

        int n = merged.size();

        double ans;

        if (n % 2 == 0) {
            ans = (merged[n / 2] + merged[(n - 1) / 2]) / 2.0;
        }
        else {
            ans = merged[n / 2];
        }

        return ans;
    }
};