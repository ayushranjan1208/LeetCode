using ll = long long;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> adj(n);

        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        const int MOD = 1e9 + 7;

        vector<pair<ll,ll>> dis(n,{1e18,0});
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        dis[0] = {0,1};
        pq.push({0,0});

        while(!pq.empty()){
            auto [time,node] = pq.top();
            pq.pop();

            if(time > dis[node].first) continue;

            for(auto &[u,w] : adj[node]){
                ll new_time = time + w;
                if(new_time < dis[u].first){
                    dis[u] = {new_time, dis[node].second};
                    pq.push({new_time, u});
                }
                else if(new_time == dis[u].first){
                    dis[u].second = (dis[u].second + dis[node].second) % MOD;
                }
            }
        }
        return dis[n - 1].second;
    }
};