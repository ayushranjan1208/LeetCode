class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);

        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        queue<int> q;
        vector<int> order;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
                order.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto child : adj[node]){
                inDegree[child]--;
                if(inDegree[child] == 0){
                    q.push(child);
                    order.push_back(child);
                }
            }
        }
        reverse(order.begin(),order.end());

        if(order.size() == n) return order;
        return {};
    }
};