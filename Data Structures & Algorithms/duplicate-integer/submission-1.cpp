class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;

        int l=*min_element(nums.begin(),nums.end());
        int h=*max_element(nums.begin(),nums.end());

        vector<int> H(h-l+1,0);

        for(int i=0;i<nums.size();i++){
            H[nums[i]-l]++;
            if(H[nums[i]-l]>1){
                return true;
            }
        }
        return false;
    }
};