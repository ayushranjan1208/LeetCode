class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> time(n + 1, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        time[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [t,node] = pq.top();
            pq.pop();

            for(auto &[u,w] : adj[node]){
                int new_time = t + w;

                if(time[u] > new_time){
                    time[u] = new_time;
                    pq.push({new_time,u});
                }
            }
        }

        int reqTime = -1;

        for(int i = 1; i <= n; i++){
            if(time[i] == 1e9) return -1;
            reqTime = max(reqTime,time[i]);
        }

        return reqTime;
    }
};