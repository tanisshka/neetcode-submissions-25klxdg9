class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int prod = 1;

            for (int j = i; j < nums.size(); j++) {
                prod *= nums[j];
                maxP = max(maxP, prod);
            }
        }

        return maxP;
    }
};
