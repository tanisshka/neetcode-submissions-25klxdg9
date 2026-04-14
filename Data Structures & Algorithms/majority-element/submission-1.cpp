#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(auto i : nums){
            freq[i]++;
        }

        int n = nums.size();
        int c = n / 2;

        for(auto i : freq){
            if(i.second > c){
                return i.first;
            }
        }
        return -1;
    }
};