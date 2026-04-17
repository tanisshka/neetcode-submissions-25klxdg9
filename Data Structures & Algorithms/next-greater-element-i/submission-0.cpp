class Solution {
private:
    vector<int> referenceArray(vector<int>& ref) {
        int n = ref.size();
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            int curr = ref[i];

            while(!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if(!st.empty()) {
                ref[i] = st.top();
            } else {
                ref[i] = -1;
            }

            st.push(curr);
        }

        return ref;
    }

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> ref = nums2;
        ref = referenceArray(ref);

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int j = 0;
            while(nums1[i] != nums2[j]) {
                j++;
            }
            ans[i] = ref[j];
        }

        return ans;
    }
};