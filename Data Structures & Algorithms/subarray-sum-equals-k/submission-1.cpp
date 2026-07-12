class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Prefix Hash approach
        int sum=0;
        int cnt=0;
        
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int require=sum-k;

            if(mp.find(require)!=mp.end()){
                cnt+=mp[require];
            }
            mp[sum]++;
        }

        return cnt;
    }
};