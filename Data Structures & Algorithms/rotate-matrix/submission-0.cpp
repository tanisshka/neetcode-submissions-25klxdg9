class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        vector<vector<int>> ans = matrix;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=ans[n-j-1][i];
            }
        }
    }
};
