class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indice;
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];

            if(indice.count(complement) && indice[complement]!=i){
                return {indice[complement],i};
            }
            indice[nums[i]]=i;
        }
    }
};
