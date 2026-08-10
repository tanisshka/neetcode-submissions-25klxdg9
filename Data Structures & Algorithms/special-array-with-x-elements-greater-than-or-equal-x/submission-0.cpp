class Solution {
private:
    bool cntNo(vector<int>& nums, int no){
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>=no){
                cnt++;
            }
        }

        return cnt==no;
    }
public:
    int specialArray(vector<int>& nums) {
        //Brute force solution
        int low = 0;
        int high=nums.size();
        int ans=-1;
        for(int i=0;i<=high;i++){
            if(cntNo(nums,i)){
                ans=i;
                break;
            }else{
                continue;
            }
        }
        return ans;
    }
};