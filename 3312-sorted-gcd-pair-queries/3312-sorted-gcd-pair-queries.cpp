class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi = *max_element(nums.begin(),nums.end());
        unordered_map<int,int> fre;

        for(auto &e : nums) fre[e]++;

        vector<long long> mul(maxi + 1,0);

        for(int i = 1; i <= maxi; i++){
            for(int j = i; j <= maxi; j += i){
                mul[i] += fre[j];
            }
        }

        for(int i = 1; i <= maxi; i++){
            mul[i] = (mul[i] * (mul[i] - 1)) / 2;
        }

        for(int i = maxi; i >= 1; i--){
            int pairs = 0;
            for(int j = i*2; j <= maxi; j += i){
                pairs += mul[j];
            }
            mul[i] -= pairs;
        }

        for(int i = 1; i <= maxi; i++){
            mul[i] += mul[i-1];
        }

        vector<int> ans;
        for(auto q : queries){
            int g = lower_bound(mul.begin(),mul.end(),q+1) - mul.begin();

            ans.push_back(g);
        }

        return ans;

    }
};