class Solution {
    void Merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        int i = low;
        int j = mid + 1;

        while(i <= mid && j <= high) {
            if(nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while(i <= mid)
            temp.push_back(nums[i++]);

        while(j <= high)
            temp.push_back(nums[j++]);

        for(int k = low; k <= high; k++)
            nums[k] = temp[k - low];
    }

    void RMerge(vector<int>& nums, int low, int high) {

        if(low >= high)
            return;

        int mid = low + (high - low) / 2;

        RMerge(nums, low, mid);
        RMerge(nums, mid + 1, high);

        Merge(nums, low, mid, high);
    }

public:
    vector<int> sortArray(vector<int>& nums) {

        RMerge(nums, 0, nums.size() - 1);
        return nums;
    }
};