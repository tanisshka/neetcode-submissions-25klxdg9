class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Brute force approach 2
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        res.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }

        vector<vector<int>> ans (res.begin(),res.end());
        return ans;
    }
};
