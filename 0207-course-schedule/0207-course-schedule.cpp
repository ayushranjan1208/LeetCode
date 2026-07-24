class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);

        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
                cnt++;
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto child : adj[node]){
                inDegree[child]--;
                if(inDegree[child] == 0){
                    q.push(child);
                    cnt++;
                }
            }
        }

        if(cnt == n) return true;
        return false;
    }
};