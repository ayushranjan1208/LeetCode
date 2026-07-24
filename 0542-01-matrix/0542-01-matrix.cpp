class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> dis(n,vector<int>(m,-1));
        queue<tuple<int,int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dis[i][j] = 0;
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            auto [r,c,d] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m || dis[nr][nc] != -1) continue;

                dis[nr][nc] = d + 1;
                q.push({nr,nc,d + 1}); 
            }
        }

        return dis;
    }
};