class Solution {
private:
    int C(int n, int r, vector<vector<int>> &dp) {
        if (r == 0 || r == n) {
            return dp[n][r] = 1;
        }

        if (dp[n][r] != -1) {
            return dp[n][r];
        }

        return dp[n][r] =
            C(n-1, r-1, dp) + C(n-1, r, dp);
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows, vector<int>(numRows, -1));
        vector<vector<int>> ans(numRows);

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                ans[i].push_back(C(i, j, dp));
            }
        }

        return ans;
    }
};