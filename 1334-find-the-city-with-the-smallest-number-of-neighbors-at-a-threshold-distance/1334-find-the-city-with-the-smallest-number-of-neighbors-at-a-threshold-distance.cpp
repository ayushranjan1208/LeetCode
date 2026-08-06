class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,1e9));

        for(int i = 0; i < n; i++) dis[i][i] = 0;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            dis[u][v] = w;
            dis[v][u] = w;
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dis[i][via] == 1e9 || dis[via][j] == 1e9) continue;

                    int dist = dis[i][via] + dis[via][j];

                    if(dis[i][j] > dist) dis[i][j] = dist;
                }
            }
        }

        int node = -1, mini = INT_MAX;

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dis[i][j] <= distanceThreshold && j != i) cnt++;
            }

            if(cnt <= mini){
                node = i;
                mini = cnt;
            }
        }

        return node;
    }
};