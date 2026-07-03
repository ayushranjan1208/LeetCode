class Solution {
public:

    bool check(vector<vector<pair<int,int>>> &adj, vector<bool> &online, long long k, int mid){
        int n = online.size();

        vector<long long> dis(n,1e18);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        pq.push({0,0});

        dis[0] = 0;

        while(!pq.empty()){
            auto [cur_cost, node] = pq.top();
            pq.pop();

            if(cur_cost > dis[node]) continue;

            if(node == n - 1){
                return true;
            }

            for(auto [child,cost] : adj[node]){
                long long new_cost = cur_cost + cost;

                if(online[child] == 0 || new_cost > k || cost < mid) continue;

                if(new_cost < dis[child]){
                    pq.push({new_cost, child});
                    dis[child] = new_cost;
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int max_cost = 0;
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            max_cost = max(max_cost,edges[i][2]);
        }

        int lo = 0, hi = max_cost;

        while(hi - lo > 1){
            int mid = lo + (hi - lo) / 2;
            if(check(adj,online,k,mid)) lo = mid;
            else hi = mid - 1;
        }
        if(check(adj,online,k,hi)) return hi;
        if(check(adj,online,k,lo))return lo;
        return -1;
    }
};