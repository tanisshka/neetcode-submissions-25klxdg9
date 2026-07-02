class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Counting approach 
        vector<int> H(3,0);

        for(int i=0;i<nums.size();i++){
            H[nums[i]]++;
        }

        int i=0;
        for(int j=0;j<H.size();j++){
            int count=H[j];
            while(count>0){
                nums[i]=j;
                i++;
                count--;
            }
        }
    }
};