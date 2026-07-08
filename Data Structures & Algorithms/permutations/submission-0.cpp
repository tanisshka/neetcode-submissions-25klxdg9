class Solution {
private: 
   void generatePermutations(vector<int>& nums, int idx, vector<vector<int>>& ans){
      if(idx==nums.size()-1){
        ans.push_back(nums);
        return;
      }else{
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            generatePermutations(nums,idx+1,ans);
            //Backtrack
            swap(nums[idx],nums[i]);
        }
      }
   }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generatePermutations(nums,0,ans);
        return ans;
    }
};
