class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dis(26,vector<int>(26,INT_MAX));

        for(int i = 0; i < 26; i++) dis[i][i] = 0;
        for(int i = 0; i < original.size(); i++){
            int u = original[i] - 'a', v = changed[i] - 'a', w = cost[i];

            dis[u][v] = min(dis[u][v], w);
        }

        for(int via = 0; via < 26; via++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dis[i][via] == INT_MAX || dis[via][j] == INT_MAX) continue;

                    int d = dis[i][via] + dis[via][j];
                    dis[i][j] = min(dis[i][j], d);
                }
            }
        }

        long long ans = 0;
        for(int i = 0; i < source.size(); i++){
            int u = source[i] - 'a', v = target[i] - 'a';
            if(dis[u][v] == INT_MAX) return -1;

            ans += 1ll * dis[u][v];
        }

        return ans;
    }
};