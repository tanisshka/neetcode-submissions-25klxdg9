class Solution {
private:
    int cntNo(vector<int>& nums, int no) {
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= no) {
                cnt++;
            }
        }

        return cnt;
    }

public:
    int specialArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size();
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(cntNo(nums, mid) == mid) {
                ans = mid;
                return ans;
            }
            else if(cntNo(nums, mid) > mid) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};