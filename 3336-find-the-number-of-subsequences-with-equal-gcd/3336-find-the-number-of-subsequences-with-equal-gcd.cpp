class Solution {
public:
    int dp[201][201][201];
    const int MOD = 1e9 + 7;
    int fun(vector<int> &nums, int ind, int gcd1, int gcd2){
        if(ind == nums.size()){
            if(gcd1 == gcd2 && gcd1 != 0) return 1;
            return 0;
        }

        if(dp[ind][gcd1][gcd2] != -1) return dp[ind][gcd1][gcd2];

        long long ans = 0;

        ans = (ans + fun(nums,ind + 1,__gcd(gcd1,nums[ind]),gcd2)) % MOD;

        ans = (ans + fun(nums,ind + 1,gcd1,__gcd(gcd2,nums[ind]))) % MOD;

        ans = (ans + fun(nums,ind + 1,gcd1,gcd2)) % MOD;

        return dp[ind][gcd1][gcd2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(nums,0,0,0);
    }
};