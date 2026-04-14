class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        vector<int> f(size + 2, 0);

        for (int i = 0; i < size; i++) {
            f[i + 1] = flowerbed[i];
        }

        for (int i = 1; i <= size; i++) {
            int left = i - 1;
            int right = i + 1;

            if (f[left] == 0 && f[i] == 0 && f[right] == 0) {
                f[i] = 1;  
                n--;

                if (n == 0) return true;
            }
        }

        return n <= 0;
    }
};