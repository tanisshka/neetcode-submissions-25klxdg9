class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int dayN = 1;
            int cnt = 0;

            for(int i = 0; i < weights.size(); i++) {
                if(cnt + weights[i] <= mid) {
                    cnt += weights[i];
                } else {
                    dayN++;
                    cnt = weights[i];
                }
            }

            if(dayN <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};