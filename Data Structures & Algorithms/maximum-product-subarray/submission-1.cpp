class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Prefix & suffix
        int pre=1;
        int suf=1;
        int maxP=INT_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++){
          if(pre==0) {
            pre=1;
          }
          if(suf==0){
            suf=1;
          }

          pre*=nums[i];
          suf*=nums[n-1-i];
          maxP=max(maxP,max(pre,suf));
        }
        return maxP;
    }
};
