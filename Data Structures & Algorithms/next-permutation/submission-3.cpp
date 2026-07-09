class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //1.Find the breakpoint
        int ind=-1;
        int n=nums.size();

        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                ind=i;
                break;
            }
        }

        //2.If the breakpoint is invalid
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //3.If the breakpoint is valid
        //Find the number greater then the pivot element & swap them
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[ind],nums[i]);
                break;
            }
        }

        //4.Reverse the remaining suffix
        reverse(nums.begin()+ind+1,nums.end());
    }
};