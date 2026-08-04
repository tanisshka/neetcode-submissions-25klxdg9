class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxN = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = maxN;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int total = 0;
            for (int pile : piles) {
                total += (pile + mid - 1) / mid;
            }

            if (total <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
