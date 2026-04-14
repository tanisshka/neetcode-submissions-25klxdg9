class Solution {
private:
    int BFS(int row, int col, vector<vector<bool>> &vis, vector<vector<int>> &grid) {
        vis[row][col] = true;
        queue<pair<int,int>> q;
        q.push({row,col});

        int n = grid.size();
        int m = grid[0].size();

        int perimeter = 0;

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int drow[4] = {-1,0,1,0};
            int dcol[4] = {0,-1,0,1};

            for(int i=0;i<4;i++) {
                int nrow = r + drow[i];
                int mcol = c + dcol[i];

                if(nrow < 0 || nrow >= n || mcol < 0 || mcol >= m || grid[nrow][mcol] == 0) {
                    perimeter++;
                }
                else if(!vis[nrow][mcol]) {
                    vis[nrow][mcol] = true;
                    q.push({nrow,mcol});
                }
            }
        }

        return perimeter;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));

        int perimeter = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && !vis[i][j]) {
                    perimeter = BFS(i,j,vis,grid);
                }
            }
        }

        return perimeter;
    }
};