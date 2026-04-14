class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int c = n / 2;
        int freq = 1;
        int ans=-1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                freq++;
            } else {
                freq = 1;
            }

            if(freq > c){
                ans=nums[i];
                return ans;  
            }
        }

        if(freq>c){
            return nums[n-1];
        }
        return ans;
    }
};