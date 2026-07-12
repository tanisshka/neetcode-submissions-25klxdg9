class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        // Optimized Hashing approach
        vector<int> ans;
        unordered_map<int, int> Hash;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            Hash[nums[i]]++;

            if (Hash[nums[i]] == (n / 3) + 1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};