class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<tuple<int,int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    vis[i][j] = 1;
                }
            }
        }
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        int time = 0;
        while(!q.empty()){
            auto [r,c,t] = q.front();
            q.pop();
            
            time = max(time,t);

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];

                if(nr >= n || nr < 0 || nc >= m || nc < 0 || vis[nr][nc] || grid[nr][nc] == 0) continue;

                vis[nr][nc] = 1;
                q.push({nr,nc,t + 1});
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) return -1;
            }
        }
        return time;
    }
};