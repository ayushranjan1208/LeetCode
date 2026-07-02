class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        priority_queue<pair<pair<int,int>,int>> pq;

        health -= grid[0][0];
        pq.push({{0,0},health});

        vis[0][0] = health;

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,-1,0,1};

        while(!pq.empty()){
            auto p = pq.top();
            int r = p.first.first, c = p.first.second, cur_health = p.second;
            pq.pop();

            if(r == n - 1 && c == m - 1){
                if(cur_health >= 1) return true;
            }

            for(int i = 0; i < 4; i++){
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= n || nr < 0 || nc >= m || nc < 0) continue;

                int h = cur_health - grid[nr][nc];
                if(vis[nr][nc] < h){
                    vis[nr][nc] = h;
                    pq.push({{nr,nc},h});
                }
            }
        }
        return false;

    }
};