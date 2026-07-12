class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> Hash;
        int n=nums.size();
        for(int i=0;i<n;i++){
            Hash[nums[i]]++;
        }

        for(auto it:Hash){
            if(it.second > (n/3)){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};