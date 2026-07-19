class Solution {
public:
    vector<long long> dp;

    int valid(vector<vector<string>>& rules, vector<int>& costs, string &source, string &target, int l, int r){
        int cost = INT_MAX;
        for(int j = 0; j < rules.size(); j++){
            string &pat = rules[j][0];
            string &rep = rules[j][1];
            int c = costs[j];


            if(pat.size() != (r-l + 1)) continue;

            for(int i = 0; i < pat.size(); i++){
                if(rep[i] != target[l + i]){
                    c = INT_MAX;
                    break;
                }
                if(pat[i] == '*' || source[l + i] == pat[i]){
                    c += (pat[i] == '*');
                }
                else{
                    c = INT_MAX;
                    break;
                }
            }
            cost = min(cost,c);
        }
        return cost;
    }

    long long fun(vector<vector<string>>& rules, vector<int>& costs, string &source, string &target, int ind){
        if(ind == source.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        long long cost = INT_MAX;

        if(source[ind] == target[ind]) cost = fun(rules,costs,source,target,ind + 1);

        for(int i = ind; i < ind + 20 && i < source.size(); i++){

            int temp = valid(rules,costs,source,target,ind,i);

            if(temp == INT_MAX) continue;

            cost = min(cost, temp + fun(rules,costs,source,target,i + 1));
        }

        return dp[ind] = cost;
    }
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.size();
        dp.assign(n,-1);

        if(source == target) return 0;

        long long cost = fun(rules,costs,source,target,0);

        if(cost >= INT_MAX) return -1;
        return cost;
    }
};