class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int i:nums){
            freq[i]++;
        }

        int maxFreq=0;
        int element=-1;

        for(auto i:freq){
            if(i.second>maxFreq){
                maxFreq=i.second;
                element=i.first;
            }
        }

        return element;
    }
};