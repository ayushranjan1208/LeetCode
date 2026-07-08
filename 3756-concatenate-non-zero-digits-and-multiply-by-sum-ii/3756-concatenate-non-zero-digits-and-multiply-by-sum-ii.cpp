class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<vector<long long>> pre(n+1,vector<long long>(3,0));
        long long num = 0, sum = 0, c = 0;

        vector<long long> pow10(n+1,1);
        for(int i = 1; i <= n; i++){
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        for(int i = 0; i < n; i++){
            long long d = s[i] - '0';
            if(d){
                num = (num * 10 + d) % MOD;
                sum += d;
                c++;
            }
            pre[i+1] = {num,sum,c};
        }
        int q = queries.size();
        vector<int> res(q);
        for(int i = 0; i < q; i++){
            int l = queries[i][0] , r = queries[i][1] + 1;

            long long left_num = pre[l][0], right_num = pre[r][0];
            long long summ = pre[r][1] - pre[l][1];
            long long digits = pre[r][2] - pre[l][2];

            left_num = (left_num * pow10[digits]) % MOD;
            long long ans = (right_num - left_num + MOD) % MOD;
            ans = (ans * summ) % MOD;
            res[i] = ans;
        }
        return res;
    }
};