class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        unordered_map<int,int> mp;
        vector<int> ans;

        for(auto i:nums1){
            mp[i]++;
        }

        for(auto i:nums2){
            if(mp[i]>0){
                s.insert(i);
            }
        }

        for(auto itr:s){
            ans.push_back(itr);
        }

        return ans;
     
    }
};