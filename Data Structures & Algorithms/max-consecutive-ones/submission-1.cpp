class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> ans;
        int i = 0;

        while (i < nums.size()) {
            int count = 0;

            while (i < nums.size() && nums[i] == 1) {
                count++;
                i++;
            }

            ans.push_back(count);
            i++; 
        }

        return *max_element(ans.begin(), ans.end());
    }
};
