class Solution {
private:
    bool isSafe(vector<string> &board,int row,int col,int n){
        //check column
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //check upper-left diagonal 
        for(int i=row-1,j=col-1;i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        //check upper-right diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void placeQueen(vector<string> &board,int row,int n,vector<vector<string>> &ans){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                placeQueen(board,row+1,n,ans);

                //backtrack
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n,string (n,'.'));
        vector<vector<string>> ans;
        placeQueen(board,0,n,ans);
        return ans;
    }
};
