class Solution {
private:
    void makeRow(vector<vector<int>>& matrix,int i){
        int m=matrix[0].size();
        for(int j=0;j<m;j++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-1;
            }
        }
    }

    void makeCol(vector<vector<int>>& matrix,int j){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-1;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Brute force approach
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    makeRow(matrix,i);
                    makeCol(matrix,j);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
