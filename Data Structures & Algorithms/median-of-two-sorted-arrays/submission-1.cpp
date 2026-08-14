class Solution {
   private:
    double median(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0;
        int j = 0;

        int t = n + m;
        int idx2 = t / 2;
        int idx1 = idx2 - 1;

        int idx1el = -1;
        int idx2el = -1;

        int cnt=0;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                if (cnt == idx1) idx1el = nums1[i];
                if (cnt == idx2) idx2el = nums1[i];

                cnt++;
                i++;
            } else {
                if (cnt == idx1) idx1el = nums2[j];
                if (cnt == idx2) idx2el = nums2[j];

                cnt++;
                j++;
            }
        }

        while (i < n) {
            if (cnt == idx1) idx1el = nums1[i];
            if (cnt == idx2) idx2el = nums1[i];

            cnt++;
            i++;
        }

        while (j < m) {
            if (cnt == idx1) idx1el = nums2[j];
            if (cnt == idx2) idx2el = nums2[j];

            cnt++;
            j++;
        }

        double ans;
        if(t%2==0){
            ans=(idx1el+idx2el)/2.0;
        }else{
            ans=idx2el;
        }

        return ans;
    }

   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return median(nums1,nums2);
    }
};
