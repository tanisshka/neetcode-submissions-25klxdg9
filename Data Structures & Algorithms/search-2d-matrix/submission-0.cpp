class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int l = 0;
        int h = matrix.size() - 1;
        int idx = -1;

        // Find the last row whose first element <= target
        while(l <= h) {
            int m = l + (h - l) / 2;

            if(matrix[m][0] <= target) {
                idx = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        if(idx == -1) return false;

        // Binary search inside that row
        int low = 0;
        int high = matrix[0].size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(matrix[idx][mid] == target) {
                return true;
            }
            else if(matrix[idx][mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return false;
    }
};
