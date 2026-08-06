class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0,0,0});

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

        while(!pq.empty()){
            auto [d,r,c] = pq.top();
            pq.pop();

            if(d > dis[r][c]) continue;

            if(r == n - 1 && c == m - 1) return d;

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int dif = abs(heights[r][c] - heights[nr][nc]);
                dif = max(dif,d);
                if(dif < dis[nr][nc]){
                    dis[nr][nc] = dif;
                    pq.push({dif,nr,nc});
                } 
            }
        }

        return -1;
    }
};