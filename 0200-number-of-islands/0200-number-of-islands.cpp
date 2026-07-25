class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    void dfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int r, int c, int &n, int &m){
        vis[r][c] = 1;
        
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == '0' || vis[nr][nc] == 1) continue;

            dfs(grid,vis,nr,nc,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(grid,vis,i,j,n,m);
                    ans++;
                }
            }
        }

        return ans;
    }
};