class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        string a = "#" + text1;
        string b = "#" + text2;

        int n = a.length();
        int m = b.length();

        vector<vector<int>> LCS(n, vector<int>(m, 0));

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {

                if(a[i] == b[j]) {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                }
                else {
                    LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
                }
            }
        }

        return LCS[n-1][m-1];
    }
};
