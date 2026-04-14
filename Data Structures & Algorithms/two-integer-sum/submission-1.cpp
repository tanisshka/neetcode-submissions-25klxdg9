class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> indices;
        for(int i=0;i<nums.size();i++){
            indices[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            //Check whether complement exists in the map or not using count function 
            //Count function is used to check if a key exists or not
            if(indices.count(complement) && indices[complement]!=i){
                return {i,indices[complement]};
            }
        }
        return {};
    }
};
