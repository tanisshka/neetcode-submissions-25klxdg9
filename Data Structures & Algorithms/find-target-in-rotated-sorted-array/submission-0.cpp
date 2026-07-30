class Solution {
private:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // Assume array is not rotated
        int idx = n - 1;

        // Find pivot (largest element)
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                idx = i - 1;
                break;
            }
        }

        if (target >= nums[0] && target <= nums[idx]) {
            return binarySearch(nums, 0, idx, target);
        } else {
            return binarySearch(nums, idx + 1, n - 1, target);
        }
    }
};