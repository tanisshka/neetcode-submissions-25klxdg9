class Solution {
public:
    int findMin(vector<int> &nums) {
        int low=0;
        int high=nums.size()-1;
        int minE=INT_MAX;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[low]<=nums[mid]){
                minE=min(minE,nums[low]);
                low=mid+1;
            }else if(nums[mid]<=nums[high]){
                minE=min(minE,nums[mid]);
                high=mid-1;
            }
        }

        return minE;
    }
};
