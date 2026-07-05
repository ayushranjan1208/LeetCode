class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> spf;
    void prime(int n){
        spf.assign(n+1,-1);

        for(int i = 2; i <= n; i++){
            for(int j = i; j <= n; j += i){
                if(spf[j] == -1) spf[j] = i;
            }
        }
    }
    
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());

        prime(maxi);

        set<int> st;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            while(num > 1){
                int e = spf[num];
                st.insert(e);
                while(num % e == 0){
                    num /= e;
                }
            }
        }
        long long ans = -1;
        long long ans_k = 0;
        for(auto k : st){
            long long sum = 0;
            long long maxi = -1;
            for(int i = 0; i < n; i++){
                if(nums[i] % k) sum -= nums[i];
                else sum += nums[i];

                maxi = max(maxi,sum);
                if(sum < 0) sum = 0;
            }
            if(maxi > ans){
                ans = maxi;
                ans_k = k;
            }
        }
        if(ans_k == 0) return MOD - 2;

        return (ans * ans_k) % MOD;
    }
};