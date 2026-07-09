class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Sorting approach
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int cnt = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue; // ignore duplicates
            }
            else if (nums[i] == nums[i - 1] + 1) {
                cnt++;
            }
            else {
                longest = max(longest, cnt);
                cnt = 1;
            }
        }

        longest = max(longest, cnt);

        return longest;
    }
};