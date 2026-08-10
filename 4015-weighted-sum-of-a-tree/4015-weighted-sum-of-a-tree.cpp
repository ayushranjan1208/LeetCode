class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }

        queue<tuple<int,int,long long>> q;
        q.push({0,-1,1});

        long long sum = 0, h = -1;

        while(!q.empty()){
            auto [n,p,d] = q.front();
            q.pop();

            sum += nums[n] * (-d + 1);
            h = max(h,d);

            for(auto &ch : adj[n]){
                if(ch == p) continue;

                q.push({ch,n,d + 1});
            }
        }

        long long s = accumulate(nums.begin(),nums.end(),0ll);

        s *= h;

        sum += s;

        return sum;


    }
};