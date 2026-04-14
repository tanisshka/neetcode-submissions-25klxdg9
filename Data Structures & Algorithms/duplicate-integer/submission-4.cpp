class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> s;
        for(auto x:nums){
            s.insert(x);
        }
        if(s.size()!=nums.size()){
            return true;
        }else{
            return false;
        }
    }
};