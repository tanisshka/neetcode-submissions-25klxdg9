class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int longest=1;
        unordered_set<int> st(nums.begin(),nums.end());

        for(auto x:st){
            //If x-1 does not exist
            if(st.find(x-1)==st.end()){
                int curr=x;
                int cnt=1;

                while(st.find(curr+1)!=st.end()){
                    curr++;
                    cnt++;
                }

                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};
